/*
** EPITECH PROJECT, 2023
** victory.c
** File description:
** victory
*/
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "include/my.h"
#include "include/my_navy.h"

int check_x(char character)
{
    if (character == 'x')
        return (1);
    return (0);
}

int check_if_no_more_boats(player *player)
{
    int nb = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            nb = nb + check_x(player->boat_map[i][j]);
    }
    if (nb == 14)
        return (0);
    return (1);
}
