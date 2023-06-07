/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** copy n character of a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while ((src[i] >= '\0') && (i < n)) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
