/*
** EPITECH PROJECT, 2023
** create_map.c
** File description:
** create_map
*/
#include <stdlib.h>
#include "include/my_navy.h"

int create_map(boat *boat_position, char **boat_map)
{
    for (int j = 0; j < boat_position->lenght; j++) {
        if (boat_position->start.x != boat_position->end.x) {
            boat_map[boat_position->start.y][boat_position->start.x + j] =
            boat_position->lenght + '0';
        }
        if (boat_position->start.y != boat_position->end.y) {
            boat_map[boat_position->start.y + j][boat_position->start.x] =
            boat_position->lenght + '0';
        }
    }
    return (0);
}

int start_map_creation(player *current_player)
{
    int error = 0;

    current_player->boat_map = malloc(sizeof(char *) * 8);
    current_player->fire_map = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        current_player->boat_map[i] = malloc(sizeof(char) * 8);
        current_player->fire_map[i] = malloc(sizeof(char) * 8);
        for (int j = 0; j < 8; j++) {
            current_player->fire_map[i][j] = '.';
            current_player->boat_map[i][j] = '.';
        }
    }
    for (int i = 0; i < 4; i++) {
        error = create_map(current_player->boat_position[i],
            current_player->boat_map);
        if (error == 84)
            return (84);
    }
}
