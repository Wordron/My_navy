/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** compare n characters of two strings
*/

int comparison2(char s1, char s2)
{
    if (s1 > s2)
        return (1);
    else
        return (-1);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return (0);
    for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' &&
        i + 1 < n;)
        i++;
    if (s1[i] == s2[i])
        return (0);
    return (comparison2(s1[i], s2[i]));
}
