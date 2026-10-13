
#include <stdio.h>
#include <stdlib.h>

void print_solution(int *positions, int n)
{
    int i = 0;

    while (i < n)
    {
        if (i > 0)
            printf(" ");
        printf("%d", positions[i]);
        i++;
    }
    printf("\n");
}

int is_safe(int *positions, int col, int row)
{
    int i = 0;

    while (i < col)
    {
        if (positions[i] == row ||
            positions[i] + col - i == row ||
            positions[i] - (col - i) == row)
            return (0);
        i++;
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
