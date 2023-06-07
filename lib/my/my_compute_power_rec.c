/*
** EPITECH PROJECT, 2022
** my_computer_power_rec.c
** File description:
** calculates a number to the n_th power in a recursive way
*/

int my_compute_power_rec(int nb, int p)
{
    int res_power;

    if (p == 0) {
        return (1);
    }

    if (p < 0) {
        return (0);
    }

    if (nb == 1) {
        return (nb);
    }

    res_power = my_compute_power_rec(nb, p - 1) * nb;

}
