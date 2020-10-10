#include <iostream>

const int width = 6;
const int height = 6;

void point(int x, int y, std::string arr[width][height]){
    arr[x][y] = "O";
}

void draw(std::string arr[][width]){
    std::string out;
    for (int i = 0; i < height; i++){
        for (int j = 0; j <= width; j++){
            if (j == width){
                out.append("\n");
            }
            else {
                out.append(arr[i][j] + " ");
            }
        }
    }
    std::cout << out << std::endl;
}
