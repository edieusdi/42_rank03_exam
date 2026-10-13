
#include <stdio.h>

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char **argv)
{
    char *s;
    int i;
    int j;
    int n = 0;

    if (argc != 2)
        return (1);
    s = argv[1];
    while (s[n])
        n++;
    i = 0;
    while (i < n)
    {
        j = i + 1;
        while (j < n)
        {
            if (s[i] > s[j])
                swap(&s[i], &s[j]);
            j++;
        }
        i++;
    }
    while (1)
    {
        puts(s);
        i = n - 2;
        while (i >= 0 && s[i] >= s[i + 1])
            i--;
        if (i < 0)
            break;
        j = n - 1;
        while (s[j] <= s[i])
            j--;
        swap(&s[i], &s[j]);
        i++;
        j = n - 1;
        while (i < j)
        {
            swap(&s[i], &s[j]);
            i++;
            j--;
        }
    }
    return (0);
}
