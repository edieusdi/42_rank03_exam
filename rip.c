#include "rip.h"

void    search(char *s, int index, int balance, int remove)
{
    char c;

    if (!s[index])
    {
        if(balance == 0 && remove == 0)
            puts(s);
        return;
    }
    c = s[index];
    if (remove > 0)
    {
        s[index] = ' ';
        search(s, index +1, balance , remove - 1);
        s[index] = c;
    }
    if (c == '(')
        search(s, index +1, balance + 1, remove);
    else if ( c == ')' && balance > 0)
        search(s, index +1, balance -1, remove);
}

int main (int argc, char **argv)
{
    int index = 0;
    int balance = 0;
    int remove = 0;

    if (argc != 2)
        return(1);
    while (argv[1][index])
    {
        if (argv[1][index] == '(')
            balance++;
        else if (balance > 0)
            balance--;
        else
            remove++;
        index++;
    }
    search(argv[1], 0, 0, remove + balance);
    return(0);
}
