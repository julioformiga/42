#include <unistd.h>
#include <stdio.h>

void ft_print_digit(int i)
{
    int x;
    x = i + 48;
    write(1, &x, 1);
}

void ft_print_array(int arr[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        ft_print_digit(arr[i]);
        write(1, " ", 1);
        i++;
    }
}

void ft_print_matriz(int matriz[][4], int x, int y)
{
    int i, j;

    i = 0;
    j = 0;
    while (i < x)
    {
        while (j < y)
        {
            ft_print_digit(matriz[i][j]);
            write(1, " ", 1);
            j++;
        }
        j = 0;
        i++;
        write(1, "\n", 1);
    }
}

int *ft_resolv_puzzle(int matriz[][4], int lines[4][2], int cols[4][2], int try)
{
    int c, l;

    c = 0;
    l = 0;
    if (try < 3)
    {
        printf("\nTry #%d\n", try);
        ft_print_matriz(matriz, 4, 4);
        while (c < 4)
        {
            if (lines[c][0] == 1)
                matriz[c][0] = 4;
            if (lines[c][1] == 1)
                matriz[c][4-1] = 4;
            if (cols[c][0] == 1)
                matriz[0][c] = 4;
            if (cols[c][1] == 1)
                matriz[4-1][c] = 4;
            if (lines[c][0] == 4)
            {
                matriz[c][0] = 1;
                matriz[c][1] = 2;
                matriz[c][2] = 3;
                matriz[c][3] = 4;
            }
            if (lines[c][1] == 4)
            {
                matriz[c][0] = 4;
                matriz[c][1] = 3;
                matriz[c][2] = 2;
                matriz[c][3] = 1;
            }
            if (cols[c][0] == 4)
            {
                matriz[0][c] = 1;
                matriz[1][c] = 2;
                matriz[2][c] = 3;
                matriz[3][c] = 4;
            }
            if (cols[c][1] == 4)
            {
                matriz[0][c] = 4;
                matriz[1][c] = 3;
                matriz[2][c] = 2;
                matriz[3][c] = 1;
            }
            c++;
        }
        ft_resolv_puzzle(matriz, lines, cols, ++try);
    }
    return (matriz[4]);
}

int main(void)
{
    /* int array_lines[4][2] = { */
    /*     {4, 1}, */
    /*     {3, 2}, */
    /*     {2, 2}, */
    /*     {1, 2} */
    /* }; */
    /* int array_cols[4][2] = { */
    /*     {4, 1}, */
    /*     {3, 2}, */
    /*     {2, 2}, */
    /*     {1, 2} */
    /* }; */
    int array_lines[4][2] = {
        {3, 2},
        {2, 2},
        {2, 1},
        {1, 3}
    };
    int array_cols[4][2] = {
        {4, 1},
        {2, 2},
        {1, 2},
        {3, 2}
    };
    int matriz[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int matriz_x = sizeof(matriz) / sizeof(matriz[0]);
    int matriz_y = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    ft_resolv_puzzle(matriz, array_lines, array_cols, 0);
    /* ft_print_matriz(matriz, matriz_x, matriz_y); */
    return (0);
}
