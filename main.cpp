#include <iostream>
#include <string>
#include <unistd.h>
#include "grid.h"

int main(int argc, char const *argv[])
{
    std::string arr[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j <= width; j++){
            arr[i][j] = "*";
        }
    }
    draw(arr);
    point(0, 1, arr);
    draw(arr);
    // for (int i = 0; i < 3; i++){
    //     std::cout << ".";
    //     fflush(stdout);
    //     sleep(1);
    // }
    return 0;
}
