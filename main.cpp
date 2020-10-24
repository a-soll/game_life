#include "grid.h"
#include <iostream>
#include <string>

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
