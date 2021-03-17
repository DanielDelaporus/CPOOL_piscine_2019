/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** No file there, just an epitech header example
*/

int my_strlen(char const *s);

char *my_strcat(char *dest, char const *src)
{
    int size_dest = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[size_dest + i] = src[i];
    dest[size_dest + i] = '\0';

    return dest;
}