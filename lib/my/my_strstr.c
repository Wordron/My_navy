/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** find the first occurence of a string in an other string
*/

char *do_an_iteration(char *str, char const *to_find, int *i, int *j)
{
    int start = *i - *j;

    if (to_find[*j] == str[*i]) {
        if (to_find[*j + 1] == '\0' && str[*i + 1] == '\0')
            return (&str[start]);
        if (to_find[*j + 1] == '\0')
            return (&str[start]);
        if (to_find[*j + 1] == str[*i + 1])
            *j += 1;
        else
            *j = 0;
    } else {
        if (to_find[*j] == '\0')
            return (&str[start]);
        else
            *j = 0;
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    char *find = 0;

    for (i = 0; str[i] != '\0'; i++) {
        find = do_an_iteration(str, to_find, &i, &j);
        if (find != 0)
            return (find);
    }
    if (find == 0)
        return (str);
}
