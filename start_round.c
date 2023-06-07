/*
** EPITECH PROJECT, 2023
** start_round.c
** File description:
** start_round
*/
#include <unistd.h>
#include "include/my_navy.h"

int player_one_round(game *my_navy)
{
    int win = 0;
    int check_win = 0;
    int check_loose = 0;

    check_win = start_attack(my_navy);
    if (check_win == 1)
        return (0);
    write(1, "waiting for enemy's attack...\n", 30);
    check_loose = interprete_signal(my_navy);
    if (check_loose == 1)
        return (1);
    win = start_round(my_navy, 1);
    return (win);
}

int player_two_round(game *my_navy)
{
    int win = 0;
    int check_win = 0;
    int check_loose = 0;

    write(1, "waiting for enemy's attack...\n", 30);
    check_loose = interprete_signal(my_navy);
    if (check_loose == 1)
        return (1);
    check_win = start_attack(my_navy);
    if (check_win == 1)
        return (0);
    win = start_round(my_navy, 2);
    return (win);
}

int start_round(game *my_navy, int who)
{
    print_two_map(my_navy->me->boat_map, my_navy->me->fire_map);
    if (who == 1) {
        return (player_one_round(my_navy));
    } else {
        return (player_two_round(my_navy));
    }
}
