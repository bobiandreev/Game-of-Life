//
// Created by bobia on 09/03/2020.
//

#include <iostream>
#include "grid.h"
int main(int argc, char *argv[]){
    Grid grid(4,3);
    grid.set(1, 2, Cell::ALIVE);
    grid.set(2, 2, Cell::ALIVE);
    grid.set(3, 2, Cell::ALIVE);
    grid.set(3, 1, Cell::ALIVE);
    grid.set(2, 0, Cell::ALIVE);
    grid.print(grid);
    //grid.resize(4,2);
    //grid.print(grid);
    //grid.resize(4,3);
    //grid.print(grid);
   // grid.resize(8,2);
    //std::cout << grid.get_dead_cells() << std::endl;
    //std::cout << grid.get(1,1) << std::endl;
    //grid(1,1) = Cell ::ALIVE;
    //grid(0,1) = Cell ::ALIVE;
    //std::cout << grid.get(1,1) << std::endl;
    //grid.set(1,1,Cell::DEAD);
    //std::cout << grid.get(1,1) << std::endl;
    //grid.rotate(1);

   // grid.print(grid);

    Grid h = grid.rotate(2);
    h.print(h);
    //std::cout<<h.get_dead_cells();
//    std::cout << h.get_height() << std::endl;
//    std::cout << h.get_width() << std::endl;
    Grid z = grid.rotate(-2);
    z.print(z);
    //Grid k = h.rotate(-22);

    //k.print(k);

  //  std::cout << grid.get_total_cells() << std::endl;
  //  std::cout << grid.get_dead_cells() << std::endl;
  //  std::cout << grid.get_height() << std::endl;

}

