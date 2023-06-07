/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** display
*/
#include <unistd.h>
#include "include/my.h"

int print_map(char **map, char *which_postion)
{
    write(1, which_postion, my_strlen(which_postion));
    write(1, " |A B C D E F G H\n-+---------------\n", 36);
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1);
        write(1, "|", 1);
        for (int j = 0; j < 7; j++) {
            write(1, &(map[i][j]), 1);
            write(1, " ", 1);
        }
        write(1, &(map[i][7]), 1);
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}

void print_two_map(char **boat_map, char **fire_map)
{
    print_map(boat_map, "my positions:\n");
    print_map(fire_map, "enemy's positions:\n");
}

void write_pid(int pid)
{
    write(1, "my_pid: ", 8);
    my_put_nbr(pid);
    write(1, "\n", 1);
}

void display_h(void)
{
    write(1, "USAGE:\n\t./navy [first_player_pid] position_script\n", 50);
    write(1, "DESCRIPTION:\n\t- first_player_pid: only for second playe", 55);
    write(1, "r. Will be shown on the screen of the first player\n\t", 52);
    write(1, "- position_script: file representing the positions of the", 57);
    write(1, " boats\n", 7);
}
