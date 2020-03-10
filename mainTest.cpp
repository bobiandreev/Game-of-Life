//
// Created by bobia on 09/03/2020.
//

#include <iostream>
#include "grid.h"
int main(int argc, char *argv[]){
    Grid grid(8,8);
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            grid.set(x, y, Cell::ALIVE);
        }
    }
    grid.resize(8,2);
    //std::cout << grid.get_dead_cells() << std::endl;
    //std::cout << grid.get(1,1) << std::endl;
    //grid(1,1) = Cell ::ALIVE;
    //grid(0,1) = Cell ::ALIVE;
    //std::cout << grid.get(1,1) << std::endl;
    //grid.set(1,1,Cell::DEAD);
    //std::cout << grid.get(1,1) << std::endl;

    std::cout << '+';
    for (int i = 0; i < grid.get_width(); ++i) {
        std::cout << '-';
    }
    std::cout << '+' << std::endl;
    for (int y = 0; y < grid.get_height(); ++y) {
        std::cout << '|';
        for (int x = 0; x < grid.get_width(); ++x) {
            //int one_d_index = x * grid_height + y;
            if(grid.get(x,y)=='#'){
                std::cout << '#';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '|' << std::endl;
    }
    std::cout << '+';
    for (int i = 0; i < grid.get_width(); ++i) {
        std::cout << '-';
    }
    std::cout << '+' << std::endl;
    std::cout << grid.get_total_cells() << std::endl;
    std::cout << grid.get_dead_cells() << std::endl;
    std::cout << grid.get_height() << std::endl;

}

