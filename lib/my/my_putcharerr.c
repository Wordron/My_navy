/*
** EPITECH PROJECT, 2022
** my_putcharerr.c
** File description:
** displays an error message
*/
#include <unistd.h>

void my_putcharerr(char c)
{
    write(2, &c, 1);
}
