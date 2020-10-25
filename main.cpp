#include <iostream>
#include <string>
#include <unistd.h>

const int height = 10;
const int width = 10;

void point(int x, int y, int arr[width][height]) {
    arr[x][y] = 0;
}

void generate(int arr[][height]) {
    FILE *field;
    field = fopen("./field", "r");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            arr[i][j] = 0;
        }
    }

    if (field) {
        int num;
        int x = 0;
        int y = 0;
        while ((num = getc(field)) != EOF) {
            if (num == '1') {
                arr[x][y] = 1;
            }
            if (num == '\n') {
                x++;
                y = 0;
            } else {
                y++;
            }
        }
    }
    fclose(field);
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

void evaluate(int arr[][width], int next[][width], int neighbors, int x, int y) {
    bool live = arr[x][y];
    if (live && neighbors < 2 || neighbors > 3) {
        next[x][y] = 0;
    } else if (live == false && neighbors == 3) {
        next[x][y] = 1;
    }
    else{
        next[x][y] = arr[x][y];
    }
}

int count_neighbors(int arr[][width], int x, int y) {
    int x_pos = -1;
    int y_pos = -1;
    int x_count = 2;
    int y_count = 2;
    int sum = 0;

    for (int i = x_pos; i < x_count; i++) {
        for (int j = y_pos; j < y_count; j++) {
            int tmp_x = x + i;
            int tmp_y = y + j;
            if (tmp_x < 0) {
                tmp_x = width - 1;
            } else if (tmp_x >= width) {
                tmp_x = 0;
            }
            if (tmp_y < 0) {
                tmp_y = height - 1;
            } else if (tmp_y >= height) {
                tmp_y = 0;
            }
            sum += arr[tmp_x][tmp_y];
        }
    }
    sum -= arr[x][y];
    return sum;
}

int main(int argc, char const *argv[]) {
    int arr[height][width];
    int next[height][width];

    generate(arr);
    draw(arr);
    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int neighbors = count_neighbors(arr, i, j);
            evaluate(arr, next, neighbors, i, j);
        }
    }
    draw(next);
}
