
#include <stdio.h>
#include <stdlib.h>

void sort_letters(char *letters)
{
    int index = 0;
    int comparison_index;
    char saved_character;

    while (letters[index])
    {
        comparison_index = index + 1;
        while (letters[comparison_index])
        {
            if (letters[index] > letters[comparison_index])
            {
                saved_character = letters[index];
                letters[index] = letters[comparison_index];
                letters[comparison_index] = saved_character;
            }
            comparison_index++;
        }
        index++;
    }
}

void search(char *letters, char *result, int length, int index)
{
    int choice_index = 0;
    char saved_character;

    if (index == length)
    {
        result[index] = '\0';
        puts(result);
        return;
    }
    while (choice_index < length)
    {
        if (letters[choice_index])
        {
            saved_character = letters[choice_index];
            result[index] = saved_character;
            letters[choice_index] = '\0';
            search(letters, result, length, index + 1);
            letters[choice_index] = saved_character;
        }
        choice_index++;
    }
}

int main(int argument_count, char **argument_values)
{
    int length = 0;
    char *result;

    if (argument_count != 2)
        return (1);
    while (argument_values[1][length])
        length++;
    result = malloc(length + 1);
    if (!result)
        return (1);
    sort_letters(argument_values[1]);
    search(argument_values[1], result, length, 0);
    free(result);
    return (0);
}
