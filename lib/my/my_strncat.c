/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** concatenates n character of a string at the end of another one
*/

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    for (j = 0; src[j] != '\0' && j < n; j++) {
        dest[i] = src[j];
        i++;
    }
    return (dest);
}
