/*
** EPITECH PROJECT, 2023
** shoot.c
** File description:
** shoot
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "include/my.h"
#include "include/my_navy.h"

int verif_shoot(int x, int y, player *target, player *player)
{
    if (player->fire_map[y][x] == '.')
        return (0);
    return (1);
}

int shoot(game *my_navy, char *attack)
{
    int x = 0;
    int y = 0;

    x = attack[0] - 'A';
    y = attack[1] - '0' - 1;
    if ((x < 0 || x > 7) | (y < 0 || y > 7) ||
        my_navy->me->fire_map[y][x] != '.' || my_strlen(attack) != 3) {
        write(1, "wrong position\n", 15);
        start_attack(my_navy);
        return (0);
    }
    return (1);
}

int start_attack(game *my_navy)
{
    char *attack = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    int reception = 0;
    struct timespec *req = malloc(sizeof(struct timespec));

    req->tv_nsec = 50;
    write(1, "attack: ", 8);
    lineSize = getline(&attack, &len, stdin);
    if (shoot(my_navy, attack) == 0)
        return (0);
    send_sig(attack[0] - 'A', my_navy->adversary->terminal);
    nanosleep(req, NULL);
    send_sig(attack[1] - '0' - 1, my_navy->adversary->terminal);
    reception = interpret_spe_signal(my_navy->me, attack);
    return (reception);
}
