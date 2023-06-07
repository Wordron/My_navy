/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** show if a number is prime or not
*/

int my_is_prime(int nb)
{
    int test = 3;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (0);
    if (nb == 2)
        return (1);
    if ((nb % 2) == 0)
        return (0);
    for (test = 3; (nb / 2) >= test; test = test + 2) {
        if ((nb % test) == 0 && (nb / test) != 1)
            return (0);
    }
    return (1);
}
