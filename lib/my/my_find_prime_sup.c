/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** find the smallest prime number greater than the given number
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = my_is_prime(nb);

    for (i; i == 0; nb++) {
        i = my_is_prime(nb + 1);
    }
    return (nb);
}
