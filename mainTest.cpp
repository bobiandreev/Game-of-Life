//
// Created by bobia on 09/03/2020.
//

#include <iostream>
#include "grid.h"
#include "world.h"
#include "zoo.h"

int main(int argc, char *argv[]) {
//    std::cout << Zoo::glider() << std::endl;
//    std::cout << Zoo::r_pentomino() << std::endl;
//    std::cout << Zoo::light_weight_spaceship() << std::endl;

  //  std::cout << Zoo::load_ascii("../test_inputs/GLIDER.gol");
    //Grid grid = Zoo::load_ascii("../test_inputs/GLIDER.gol");
    Grid grid;
    Zoo::save_ascii("../test_outputs/SAVE_ASCII_GLIDER_NOTHROW.gol", grid);
}

