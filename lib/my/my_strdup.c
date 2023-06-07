/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** allocates enough memory to copy a
** string into that memory zone
*/
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    int j = 0;
    char *dest;

    while (src[i] != '\0') {
        i++;
    }
    dest = malloc(sizeof(char) * i);
    for (j = 0; j < i; j++) {
        dest[j] = src[j];
    }
    dest[j] = '\0';
    return (dest);
}
