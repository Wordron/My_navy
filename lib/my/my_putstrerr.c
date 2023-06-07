/*
** EPITECH PROJECT, 2022
** my_putstrerr.c
** File description:
** displays an error string
*/
#include "my.h"

int my_putstrerr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putcharerr(str[i]);
        i = i + 1;
    }
}
