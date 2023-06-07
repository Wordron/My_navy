/*
** EPITECH PROJECT, 2023
** interpret_interpret_signal.c
** File description:
** interpret_interpret_signal.c
*/
#include <unistd.h>
#include "include/my_navy.h"

int change_map(player *me, char *attack, int spe)
{
    if (spe == 1) {
        write(1, attack, 2);
        write(1, ": missed\n\n", 10);
        me->fire_map[attack[1] - '0' - 1][attack[0] - 'A'] = 'o';
    }
    if (spe == 2) {
        write(1, attack, 2);
        write(1, ": hit\n\n", 7);
        me->fire_map[attack[1] - '0' - 1][attack[0] - 'A'] = 'x';
    }
    if (spe == 3) {
        write(1, attack, 2);
        write(1, ": hit\n\n", 7);
        print_two_map(me->boat_map, me->fire_map);
        write(1, "I won\n\n", 7);
        me->fire_map[attack[1] - '0' - 1][attack[0] - 'A'] = 'x';
        return (1);
    }
}

int check_if_hit(game *my_navy, int x, int y)
{
    char c_x = x + 'A';
    char c_y = y + '0' + 1;

    if (my_navy->me->boat_map[y][x] != '.') {
        my_navy->me->boat_map[y][x] = 'x';
        write(1, &c_x, 1);
        write(1, &c_y, 1);
        write(1, ": hit\n\n", 7);
        if (check_if_no_more_boats(my_navy->me) == 0) {
            send_sig(3, my_navy->adversary->terminal);
            print_two_map(my_navy->me->boat_map, my_navy->me->fire_map);
            write(1, "Enemy won\n\n", 11);
            return (1);
        }
        send_sig(2, my_navy->adversary->terminal);
        return (0);
    }
    return (2);
}

int check_if_missed(game *my_navy, int x, int y)
{
    char c_x = x + 'A';
    char c_y = y + '0' + 1;

    if (my_navy->me->boat_map[y][x] == '.') {
        my_navy->me->boat_map[y][x] = 'o';
        send_sig(1, my_navy->adversary->terminal);
        write(1, &c_x, 1);
        write(1, &c_y, 1);
        write(1, ": missed\n\n", 10);
        return (0);
    }
}
