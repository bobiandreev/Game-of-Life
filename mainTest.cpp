//
// Created by bobia on 09/03/2020.
//

#include <iostream>
#include "grid.h"
#include "world.h"

int main(int argc, char *argv[]) {
    Grid g(6);

    g.set(1, 3, Cell::ALIVE);
    g.set(2, 3, Cell::ALIVE);
    g.set(3, 3, Cell::ALIVE);
    g.set(3, 2, Cell::ALIVE);
    g.set(2, 1, Cell::ALIVE);

    World w(g);
    std::cout << w.get_state() << std::endl;
    w.advance(12,false);
    std::cout << w.get_state() << std::endl;
}

