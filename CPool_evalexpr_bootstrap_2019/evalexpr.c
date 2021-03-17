/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** No file there, just an epitech header example
*/

#include"lib/my/my_getnbr.c"
#include<stdio.h>
#include<stdlib.h>

int  number(char  **str)
{
    char *s = *str;
    return my_getnbr(s);
}