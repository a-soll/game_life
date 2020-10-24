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

// void check_live(int next[][width], int x, int y, int* neighbors) {
//     if (spot) {
//         if (*neighbors < 2) {
//             std::cout << "hey";
//         }
//     }
// }

void count_neighbors(int arr[][width], int x, int y, int *sum) {
    int x_pos = -1;
    int y_pos = -1;
    int x_count = 1;
    int y_count = 1;

    if (x == 0) {
        x_pos = 0;
    }
    if (y == 0) {
        y_pos = 0;
    }
    if (x != width - 1) {
        x_count = 2;
    }
    if (y != width - 1) {
        y_count = 2;
    }

    for (int i = x_pos; i < x_count; i++) {
        for (int j = y_pos; j < y_count; j++) {
            *sum += arr[i + x_pos][y + y_pos];
        }
    }
    sum -= arr[x][y];
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int arr[height][width];
    int next[height][width];
    int neighbors = 0;

    generate(arr);
    draw(arr);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            count_neighbors(arr, i, j, &neighbors);
            if (neighbors > 0) {
                std::cout << neighbors << std::endl;
            }
            neighbors = 0;
        }
    }
}
