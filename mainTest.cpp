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
    // Grid grid = Zoo::load_ascii("../test_inputs/GLIDER.gol");
    //Grid grid;
    //Zoo::save_ascii("../test_outputs/SAVE_ASCII_GLIDER_NOTHROW.gol", grid);
    //Zoo::load_binary("../test_inputs/GLIDER.bgol");
    // Grid grid(32, 10);
    Grid g(3);

    g.set(1, 0, Cell::ALIVE);
    g.set(2, 1, Cell::ALIVE);
    g.set(0, 2, Cell::ALIVE);
    g.set(1, 2, Cell::ALIVE);
    g.set(2, 2, Cell::ALIVE);
    std::cout << g;
    Grid g90 = g.rotate(1);
    //  grid.merge(g, 1, 1, true);
    std::cout << "Grid at 90" << std::endl;
    std::cout << g90;
    std::cout << "Grid at 180" << std::endl;
    Grid g0 = g.rotate(2);
    std::cout << g0;

}

