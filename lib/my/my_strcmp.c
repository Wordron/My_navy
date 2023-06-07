/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compare two string and return a value if its the same
*/

int comparison(char s1, char s2)
{
    if (s1 > s2) {
        return (1);
    } else {
        return (-1);
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0';) {
        i++;
    }
    if (s1[i] == s2[i])
        return (0);
    return (comparison(s1[i], s2[i]));
}
