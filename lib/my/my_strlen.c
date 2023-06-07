/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** count the number of characterin a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
