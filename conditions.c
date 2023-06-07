/*
** EPITECH PROJECT, 2023
** conditions.c
** File description:
** conditions
*/
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/my_navy.h"

int check_with_other_boat(player *player, int i)
{
    for (int j = 0; player->boat_position[j] != 0; j++) {
        if (i != j && player->boat_position[i]->lenght
            == player->boat_position[j]->lenght)
            return (84);
    }
    return (0);
}

int check_isame_length(player *player)
{
    for (int i = 0; player->boat_position[i] != 0; i++) {
        if (check_with_other_boat(player, i) == 84)
            return (84);
    }
    return (0);
}

int check_length_ony(player *player, int i)
{
    if ((player->boat_position[i]->end.y -
        player->boat_position[i]->start.y + 1) !=
        player->boat_position[i]->lenght)
        return (84);
    return (0);
}

int check_length_onx(player *player, int i)
{
    if ((player->boat_position[i]->end.x -
    player->boat_position[i]->start.x + 1) !=
    player->boat_position[i]->lenght)
        return (84);
    return (0);
}

int check_length_boats(player *player)
{
    int error = 0;

    for (int i = 0; i < 4; i++) {
        if (player->boat_position[i]->end.x ==
            player->boat_position[i]->start.x)
            error = check_length_ony(player, i);
        if (player->boat_position[i]->end.y ==
            player->boat_position[i]->start.y)
            error = check_length_onx(player, i);
        if (error == 84)
            return (84);
    }
    return (0);
}
