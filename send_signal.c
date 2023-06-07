/*
** EPITECH PROJECT, 2023
** send_signal.c
** File description:
** send_signal
*/
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "include/my_navy.h"

void sig_handler(int sig, siginfo_t *new, void *context)
{
    return;
}

int send_sig(int coo, int pid)
{
    struct timespec *req = malloc(sizeof(struct timespec));
    struct sigaction act;

    act.sa_sigaction = &sig_handler;
    req->tv_nsec = 50;
    for (int i = 0; i < coo; i++) {
        kill_it(pid, 12);
        sigaction(10, &act, NULL);
        pause();
    }
    nanosleep(req, NULL);
    kill_it(pid, 10);
    nanosleep(req, NULL);
}
