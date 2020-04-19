/**
 * Declares a class representing a 2d grid world for simulating a cellular automaton.
 * Rich documentation for the api and behaviour the World class can be found in world.cpp.
 *
 * The test suites provide granular BDD style (Behaviour Driven Development) test cases
 * which will help further understand the specification you need to code to.
 *
 * @author 958753
 * @date March, 2020
 */
#pragma once

// Add the minimal number of includes you need in order to declare the class.
// #include ...

#include "grid.h"

/**
 * Declare the structure of the World class for representing a 2d grid world.
 *
 * A World holds two equally sized Grid objects for the current state and next state.
 *      - These buffers should be swapped using std::swap after each update step.
 */
class World {

private:
    Grid current_state;
    Grid next_state;

    int count_neighbours(int x, int y, bool toroidal);

public:
    explicit World();

    explicit World(int square_size);

    explicit World(int width, int height);

    explicit World(Grid grid);

    const int &get_width() const;

    const int &get_height() const;

    int get_total_cells() const;

    int get_alive_cells() const;

    int get_dead_cells() const;

    void resize(int square_size);

    void resize(int width, int height);

    const Grid &get_state() const;

    void step(bool toroidal = false);

    void advance(int steps, bool toroidal = false);
};