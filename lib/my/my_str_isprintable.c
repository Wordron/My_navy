/*
** EPITECH PROJECT, 2022
** my_str_isprintable.c
** File description:
** returns one if the given string is composed only of printable character
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= ' ' && str[i] <= '~') {
            i++;
        } else {
            return (0);
        }
    }
    return (1);
}
