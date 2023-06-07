/*
** EPITECH PROJECT, 2023
** sig_related_function.c
** File description:
** sig_related_function.c
*/
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "include/my.h"

int kill_it(int pid, int signal)
{
    int error = kill(pid, signal);

    if (error != 0)
        return (84);
}
