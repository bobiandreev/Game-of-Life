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
    grid.print(grid);
    grid.resize(8,2);
    //std::cout << grid.get_dead_cells() << std::endl;
    //std::cout << grid.get(1,1) << std::endl;
    //grid(1,1) = Cell ::ALIVE;
    //grid(0,1) = Cell ::ALIVE;
    //std::cout << grid.get(1,1) << std::endl;
    //grid.set(1,1,Cell::DEAD);
    //std::cout << grid.get(1,1) << std::endl;
    //grid.rotate(1);

    grid.print(grid);

    Grid h = grid.rotate(1);

    h.print(h);

  //  std::cout << grid.get_total_cells() << std::endl;
  //  std::cout << grid.get_dead_cells() << std::endl;
  //  std::cout << grid.get_height() << std::endl;

}

