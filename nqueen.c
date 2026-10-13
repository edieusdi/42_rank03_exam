
#include <stdio.h>
#include <stdlib.h>

void print_solution(int *positions, int n)
{
    int index = 0;

    while (index < n)
    {
        if (index > 0)
            printf(" ");
        printf("%d", positions[index]);
        index++;
    }
    printf("\n");
}

int is_safe(int *positions, int col, int row)
{
    int index = 0;

    while (index < col)
    {
        if (positions[index] == row ||
            positions[index] + col - index == row ||
            positions[index] - (col - index) == row)
            return (0);
        index++;
    }
    return (1);
}

void solve(int *positions, int n, int col)
{
    int row = 0;

    if (col == n)
    {
        print_solution(positions, n);
        return;
    }
    while (row < n)
    {
        if (is_safe(positions, col, row))
        {
            positions[col] = row;
            solve(positions, n, col + 1);
        }
        row++;
    }
}

int main(int argc, char **argv)
{
    int n;
    int *positions;

    if (argc != 2)
        return (1);
    n = atoi(argv[1]);
    if (n < 1)
        return (1);
    positions = malloc(sizeof(int) * n);
    if (!positions)
        return (1);
    solve(positions, n, 0);
    free(positions);
    return (0);
}
