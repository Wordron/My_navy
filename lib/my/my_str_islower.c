/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** returns 1 if the given string is composed only of lower case character
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            i++;
        } else {
            return (0);
        }
    }
    return (1);
}
