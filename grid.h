#include <iostream>

const int width = 6;
const int height = 6;

void point(int x, int y, int arr[width][height])
{
    arr[x][y] = 0;
}

void draw(int arr[][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (j == width)
            {
                std::cout << '\n';
            }
            else
            {
                std::cout << arr[i][j];
                std::cout << ' ';
            }
        }
    }
}

void evaluate(int arr[][width])
{
    int neighbors = 0;

    for (int i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            int spot = arr[i][j];
            if (i != 0 && j != 0)
            {
                neighbors += arr[i - 1][j - 1];
            }
            if (i != 0)
            {
                neighbors += arr[i - 1][j];
                neighbors += arr[i - 1][j + 1];
            }
            if (j != 0)
            {
                neighbors += arr[i][j - 1];
                neighbors += arr[i + 1][j - 1];
            }
            neighbors += arr[i][j + 1];
            neighbors += arr[i + 1][j];
            neighbors += arr[i + 1][j + 1];
            std::cout << neighbors;
            std::cin.get();
            neighbors = 0;
        }
    }
}
