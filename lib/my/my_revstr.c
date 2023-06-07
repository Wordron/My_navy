/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverses a string of character
*/

char *my_revstr(char *str)
{
    int ct = 0;

    while (str[ct] != '\0') {
        ct++;
    }

    int j = ct - 1;
    int i = 0;
    char witness = 0;

    while (i < j) {
        witness = str[j];
        str[j] = str[i];
        str[i] = witness;
        i++;
        j--;
    }
    return (str);
}
