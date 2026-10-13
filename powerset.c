#include "powerset.h"
void    print_subset(char **argv, int *selected)
{
    int index = 2;
    int first = 1;
    while (argv[index])
    {
        if (selected[index])
        {
            if (!first)
                printf(" ");
            printf("%d", atoi(argv[index]));
            first = 0;
        }
        index++;
    }
    printf("\n");
}

void    search (char **argv, int *selected, int index, long long sum)
{
    if(!argv[index])
    {
        if(sum == atoi(argv[1]))
            print_subset(argv, selected);
        return;
    }
    selected[index] = 1;
    search(argv, selected, index+1, sum + atoi(argv[index]));
    selected[index] = 0;
    search(argv, selected, index+1, sum);
}

int main (int argc, char **argv)
{
    int *selected;
    if (argc < 2)
        return(1);
    selected = calloc(argc, sizeof(int));
    if(!selected)
        return(1);
    search(argv,selected,2, 0);
    free(selected);
    return(0);
}
