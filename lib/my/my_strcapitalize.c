/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** capitalize the first letter in every word of a string
*/

char *my_strcapitalize(char *str)
{
    int i = 1;

    for (i = 1; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }
    for (i = 1; str[i] != '\0'; i++) {
        if ((str[i - 1] == ' ' || str[i - 1] == '+' || str[i - 1] == '-')
        && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return (str);
}
