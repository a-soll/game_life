#include "grid.h"
#include <iostream>
#include <string>
#include <unistd.h>

// void check(std::string arr[height][width]){
//     for (int i = 0; i < height; i++){
//         for (int j = 0; i < width; i++){

//         }
//     }
// }

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int arr[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            int r = rand() % 2;
            arr[i][j] = r;
        }
    }
    draw(arr);
    std::cin.get();
    evaluate(arr);
    draw(arr);
    // point(0, 1, arr);

    // draw(arr);
    // return 0;
}
