/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** calculates the square root of a whole number
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    while (i * i <= nb) {
        if ((i * i) == nb) {
        return (i);
        }

        if ((i * i) < nb && nb < ((i + 1) * (i + 1))) {
            return (0);
        }

        i++;
    }
}
