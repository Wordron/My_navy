/*
** EPITECH PROJECT, 2022
** my_nblen.c
** File description:
** count the number of charaacer in a number
*/
#include "./my.h"

int check_negatif(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        return (1);
    }
    return (0);
}

int my_nblen(int nb)
{
    int temp = 0;
    char nbstr[11] = "\0";
    int j = 0;
    int negatif = check_negatif(nb);

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
    return (my_strlen(nbstr) + negatif);
}
