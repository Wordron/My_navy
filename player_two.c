/*
** EPITECH PROJECT, 2023
** player_two.c
** File description:
** player_two
*/
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include "include/my.h"
#include "include/my_navy.h"

void signal_action_p_two(int signal, siginfo_t *new, void *context)
{
    return;
}

int start_second_player_part_two(game *my_navy)
{
    write_pid(getpid());
    write(1, "successfully connected\n\n", 24);
    if (start_round(my_navy, 2) == 1)
        return (1);
    else
        return (0);
}

int start_second_player(char *filepath, int adversary_pid)
{
    game *my_navy = malloc(sizeof(game));
    struct timespec *req = malloc(sizeof(struct timespec));
    struct timespec *rem = malloc(sizeof(struct timespec));
    struct sigaction act;
    int error = 0;

    req->tv_sec = 1;
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &signal_action_p_two;
    my_navy->me = malloc(sizeof(player));
    my_navy->adversary = malloc(sizeof(player));
    my_navy->adversary->terminal = adversary_pid;
    error = create_player(my_navy->me, filepath);
    kill_it(adversary_pid, 10);
    sigaction(10, &act, NULL);
    nanosleep(req, rem);
    if (rem->tv_nsec == 0 || error == 84)
        return (84);
    return (start_second_player_part_two(my_navy));
}
