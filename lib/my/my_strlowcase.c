/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** change every letter in a string in lowercase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}
