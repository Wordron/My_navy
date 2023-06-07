/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** displays a number
*/
#include "./my.h"

int my_put_nbr(int nb)
{
    int temp = 0;
    char nbstr[11] = "\0";
    int j = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb == 0)
        nbstr[j] = '0';
    for (int i = 1; nb != 0; i++) {
        temp = nb % my_compute_power_rec(10, i);
        nb = nb - temp;
        if (i == 1)
            nbstr[j] = temp + '0';
        else
            nbstr[j] = ((temp / my_compute_power_rec(10, i - 1)) + '0');
        j++;
    }
    my_putstr(my_revstr(nbstr));
}
