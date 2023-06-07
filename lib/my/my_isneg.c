/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** display if a value is positive or negative
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (n);
}
