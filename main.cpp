#include "grid.h"
#include <iostream>
#include <string>
#include <unistd.h>

void point(int x, int y, int arr[width][height]) {
    arr[x][y] = 0;
}

void generate(int arr[][height]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            int r = rand() % 2;
            arr[i][j] = r;
        }
    }
}

void draw(int arr[][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            if (j == width) {
                std::cout << '\n';
            } else {
                std::cout << arr[i][j];
                std::cout << ' ';
            }
        }
    }
}

void check_live(bool spot, int neighbors) {
    if (spot) {
        if (neighbors == 0) {
            printf();
        }
    }
}

void count_neighbors(int arr[][width], int x, int y, int *sum) {
    int i = -1;
    int j = -1;

    if (x == 0 || x == height - 1) {
        i = 0;
    }
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            *sum += arr[x][y];
        }
    }
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int arr[height][width];
    int sum = 0;
    generate(arr);
    draw(arr);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            count_neighbors(arr, i, j, &sum);
        }
    }
}
