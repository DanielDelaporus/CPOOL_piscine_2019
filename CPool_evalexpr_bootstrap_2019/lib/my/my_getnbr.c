/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** No file there, just an epitech header example
*/

int calc_digits(int res)
{
    int new_digit = 0;
    int new_res = res;
    
    while (new_res != 0) {
        new_digit += 1;
        new_res /= 10;
    }
    return (new_digit);
}

int return_value(long res, int neg,int digit)
{
    int new_digit = calc_digits(res);

    if (res == 2147483648 && neg == -1)
        return (-2147483648);

    if (digit > 10 || digit != new_digit || res > 2147483647)
        return (0);

    return (neg * (int)res);
}

int my_getnbr(char *str)
{
    long res = 0;
    int neg = 1;
    int off = 0;
    int digit = 0;
    int end = 0;

    while (str[off]  != '\0') {
        if (str[off]  >= '0' && str[off] <= '9') {
            if ((str[off] != '0' || res != 0) && end == 0) {
                res = res * 10 + str[off] - 48;
                digit += 1;
            }
        }
        else if (res == 0 && str[off] == '-' && end == 0) 
            neg *= -1;
        else if (str[off] != '+')
            end = 1;
        off += 1;
    }
    return return_value(res, neg, digit);
}