
#include <stdio.h>
#include <stdlib.h>

void sort_letters(char *letters)
{
    int index = 0;
    int comparison_index;
    char saved;

    while (letters[index])
    {
        comparison_index = index+1;
        while (letters[comparison_index])
        {
            if(letters[index] > letters[comparison_index])
            {
                saved = letters[index];
                letters[index] = letters[comparison_index];
                letters[comparison_index] = saved;
            }
            comparison_index++;
        }
        index++;
    }
}

void search(char *letters, char *result, int len, int index)
{
    int choice_index = 0;
    char saved;

    if(index == len)
    {
        result[index] = '\0';
        puts(result);
        return;
    }
    while (choice_index < len)
    {
        if(letters[choice_index] != '\0')
        {
            saved = letters[choice_index];
            result[index] = saved;
            letters[choice_index] = '\0';
            search(letters, result, len, index +1);
            letters[choice_index] = saved;
        }
        choice_index++;
    }
}

int main (int argc, char **argv)
{
    char *result;
    int len = 0;

    if (argc != 2)
        return(1);
    while (argv[1][len])
        len++;
    result = malloc(len + 1);
    if (!result)
        return(1);
    sort_letters(argv[1]);
    search(argv[1],result,len,0);
    free(result);
    return(0);
}
