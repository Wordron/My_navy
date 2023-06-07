/*
** EPITECH PROJECT, 2023
** my_navy.h
** File description:
** my_navy
*/
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_

    typedef struct coordinate {
        int x;
        int y;
    } coordinate;

    typedef struct boat {
        int lenght;
        coordinate start;
        coordinate end;
    } boat;

    typedef struct player {
        int terminal;
        char **boat_map;
        char **fire_map;
        boat **boat_position;
    } player;

    typedef struct game {
        player *me;
        player *adversary;
    } game;

    int create_player(player *current_player, char *filepath);
    int start_map_creation(player *gamer);
    void print_two_map(char **boat_map, char **fire_map);
    void write_pid(int pid);
    int shoot(game *my_navy, char *attack);
    int start_attack(game *my_navy);
    void display_h(void);
    int send_sig(int coo, int pid);
    int kill_it(int pid, int signal);
    int interprete_signal(game *my_navy);
    int interpret_spe_signal(player *me, char *attack);
    int check_if_no_more_boats(player *player);
    void sig_handling(int sig, siginfo_t *new, void *context);
    int check_nb_boats(char *buffer);
    int check_isame_length(player *player);
    int check_length_boats(player *player);
    int check_length_onx(player *player, int i);
    int check_length_ony(player *player, int i);
    int change_map(player *me, char *attack, int spe);
    int check_if_hit(game *my_navy, int x, int y);
    int check_if_missed(game *my_navy, int x, int y);
    int start_round(game *my_navy, int who);
    int my_str_isfloat(char const *str);
    int start_second_player(char *filepath, int adversary_pid);

#endif /* !MY_NAVY_H_ */
