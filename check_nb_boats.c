/*
** EPITECH PROJECT, 2023
** check_nb_boats.c
** File description:
** check_nb_boats
*/
#include <stdio.h>
#include "include/my_navy.h"

int check_nb_boats(char *buffer)
{
    int nb = 0;
    int i = 0;

    for (i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '\n')
            nb++;
    }
    if (buffer[i] == 0)
        nb++;
    if (nb == 4)
        return (0);
    return (84);
}

int my_str_isfloat(char const *str)
{
    int i = 1;

    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0' || str[i] == '.')
            i++;
        else
            return (0);
    }
    if (str[0] == '-')
        return (1);
    if (str[0] <= '9' && str[0] >= '0')
        return (1);
    return (0);
}
