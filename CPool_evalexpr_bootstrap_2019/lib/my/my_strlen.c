/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** No file there, just an epitech header example
*/

int my_strlen(char const *str)
{
    int offset = 0;
    while (*(str + offset) != '\0')
        offset += 1;

    return (offset);
}