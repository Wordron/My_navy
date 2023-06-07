/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include "include/my.h"
#include "include/my_navy.h"

int general = -1;

void signal_action_p_one(int signal, siginfo_t *new, void *context)
{
    general = new->si_pid;
    kill_it(new->si_pid, 10);
}

int create_first_player(game *my_navy, char *filepath)
{
    my_navy->me = malloc(sizeof(player));
    my_navy->adversary = malloc(sizeof(player));
    return (create_player(my_navy->me, filepath));
}

int start_first_player(char *filepath)
{
    game *my_navy = malloc(sizeof(game));
    struct sigaction act;
    int error = 0;
    int pid = getpid();

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &signal_action_p_one;
    error = create_first_player(my_navy, filepath);
    if (error == 84)
        return (84);
    write_pid(pid);
    sigaction(10, &act, NULL);
    write(1, "waiting for enemy connection...\n\n", 33);
    pause();
    write(1, "enemy connected\n\n", 17);
    my_navy->adversary->terminal = general;
    if (start_round(my_navy, 1) == 1)
        return (1);
    else
        return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        display_h();
        return (0);
    }
    if (ac == 2)
        return (start_first_player(av[1]));
    else if (ac == 3 && my_str_isfloat(av[1]) == 1)
        return (start_second_player(av[2], my_getnbr(av[1])));
    else
        return (84);
}
