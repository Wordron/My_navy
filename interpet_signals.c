/*
** EPITECH PROJECT, 2023
** interpret_signals.c
** File description:
** interpet_signals
*/
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "include/my_navy.h"
#include "include/my.h"

extern int general;

void sig_handling(int sig, siginfo_t *new, void *context)
{
    if (sig == 12) {
        general += 10;
        kill(new->si_pid, 10);
    }
    if (sig == 10)
        general += 1;
    return;
}

void catch_coo(void)
{
    struct timespec *req = malloc(sizeof(struct timespec));
    struct sigaction act;

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &sig_handling;
    req->tv_nsec = 5;
    while (1) {
        sigaction(10, &act, NULL);
        sigaction(12, &act, NULL);
        pause();
        if ((general % 10) == 1)
            return;
    }
}

int interpret_spe_signal(player *me, char *attack)
{
    struct timespec *req = malloc(sizeof(struct timespec));
    int spe = 0;

    general = 0;
    catch_coo();
    spe = general / 10;
    req->tv_nsec = 10;
    nanosleep(req, NULL);
    return (change_map(me, attack, spe));
}

int interprete_signal(game *my_navy)
{
    struct timespec *req = malloc(sizeof(struct timespec));
    int x = 0;
    int y = 0;
    int sig = 0;

    general = 0;
    catch_coo();
    x = general / 10;
    general = 0;
    catch_coo();
    y = general / 10;
    req->tv_nsec = 10;
    nanosleep(req, NULL);
    sig = check_if_hit(my_navy, x, y);
    if (sig != 2)
        return (sig);
    return (check_if_missed(my_navy, x, y));
}
