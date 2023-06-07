/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** concatenates two strings together
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    for (j = 0; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    return (dest);
}
