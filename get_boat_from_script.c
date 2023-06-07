/*
** EPITECH PROJECT, 2023
** get_boat_from_script.c
** File description:
** get_boat_from_script.c
*/
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "include/my.h"
#include "include/my_navy.h"

char *load_file_in_mem(char const *filepath)
{
    int error = 0;
    char *buffer = malloc(sizeof(char) * (31));
    int fd = open(filepath, O_RDONLY);

    if (fd < 0) {
        free(buffer);
        return (NULL);
    }
    error = read(fd, buffer, 31);
    close(fd);
    return (buffer);
}

int check_boat_validity(boat **boat_position)
{
    for (int i = 0; i < 4; i++) {
        if (boat_position[i]->start.x + (boat_position[i]->lenght - 1) !=
        boat_position[i]->end.x && boat_position[i]->start.y +
        (boat_position[i]->lenght - 1) != boat_position[i]->end.y)
            return (84);
    }
    return (0);
}

int get_other_boat_from_file(boat **boat_position, char *buffer, int i,
    int current_boat)
{
    i += 2;
    if (buffer[i] < 'A' || buffer[i] > 'H')
        return (84);
    boat_position[current_boat]->start.x = buffer[i] - 'A';
    i++;
    if (buffer[i] < '1' || buffer[i] > '8')
        return (84);
    boat_position[current_boat]->start.y = buffer[i] - '0' - 1;
    i += 2;
    if (buffer[i] < 'A' || buffer[i] > 'H')
        return (84);
    boat_position[current_boat]->end.x = buffer[i] - 'A';
    i++;
    if (buffer[i] < '1' || buffer[i] > '8')
        return (84);
    boat_position[current_boat]->end.y = buffer[i] - '0' - 1;
    return (i);
}

int get_boat_from_file(boat **boat_position, char *buffer)
{
    int current_boat = 0;

    for (int i = 0; buffer[i] != '\0'; i += 2) {
        if (buffer[i] < '2' || buffer[i] > '5')
            return (84);
        boat_position[current_boat]->lenght = buffer[i] - '0';
        i = get_other_boat_from_file(boat_position, buffer, i, current_boat);
        current_boat++;
        if (i == 84)
            return (84);
    }
}

int create_player(player *current_player, char *filepath)
{
    char *buffer = load_file_in_mem(filepath);
    int error = 0;

    if (buffer == NULL || check_nb_boats(buffer) == 84)
        return (84);
    current_player->boat_position = malloc(sizeof(boat *) * 4);
    for (int i = 0; i < 4; i++)
        current_player->boat_position[i] = malloc(sizeof(boat));
    error = get_boat_from_file(current_player->boat_position, buffer);
    if (error == 84)
        return (84);
    if (check_isame_length(current_player) == 84 |
        check_length_boats(current_player) == 84)
        return (84);
    start_map_creation(current_player);
    free(buffer);
    return (0);
}
