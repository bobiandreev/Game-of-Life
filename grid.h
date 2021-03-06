/**
 * Declares a class representing a 2d grid of cells.
 * Rich documentation for the api and behaviour the Grid class can be found in grid.cpp.
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
#include <iostream>
#include <vector>

/**
 * A Cell is a char limited to two named values for Cell::DEAD and Cell::ALIVE.
 */
enum Cell : char {
    DEAD = ' ',
    ALIVE = '#'
};

/**
 * Declare the structure of the Grid class for representing a 2d grid of cells.
 */
class Grid {

private:

    int grid_width;
    int grid_height;

    std::vector<Cell> cells_arr;

    int get_index(int x, int y) const;


public:

    explicit Grid();

    explicit Grid(int square_grid_size);

    explicit Grid(int width, int height);

    const int &get_width() const;

    const int &get_height() const;

    int get_total_cells() const;

    int get_alive_cells() const;

    int get_dead_cells() const;

    void resize(int square_size);

    void resize(int width, int height);

    Cell get(int x, int y) const;

    Cell &operator()(int x, int y);

    const Cell &operator()(int x, int y) const;

    void set(int X, int Y, int value);

    Grid crop(int x0, int y0, int x1, int y1) const;

    void merge(Grid grid, int x0, int y0, bool alive_only = false);

    Grid rotate(int rotation) const;

    friend std::ostream &operator<<(std::ostream &stream, const Grid &grid);

    bool are_valid(int x, int y) const;

    bool are_valid_crop(int x, int y) const;

    bool are_valid_other(int x, int y) const;

};