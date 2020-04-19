/**
 * Implements a class representing a 2d grid of cells.
 *      - New cells are initialized to Cell::DEAD.
 *      - Grids can be resized while retaining their contents in the remaining area.
 *      - Grids can be rotated, cropped, and merged together.
 *      - Grids can return counts of the alive and dead cells.
 *      - Grids can be serialized directly to an ascii std::ostream.
 *
 * You are encouraged to use STL container types as an underlying storage mechanism for the grid cells.
 *
 * @author 958753
 * @date March, 2020
 */
#include <iostream>
#include "grid.h"


/**
 * Grid::Grid()
 *
 * Construct an empty grid of size 0x0.
 * Can be implemented by calling Grid::Grid(square_size) constructor.
 *
 * @example
 *
 *      // Make a 0x0 empty grid
 *      Grid grid;
 *
 */

Grid::Grid() : grid_width(0), grid_height(0), cells_arr(0) {}

/**
 * Grid::Grid(square_size)
 *
 * Construct a grid with the desired size filled with dead cells.
 * Single value constructors should be marked "explicit" to prevent them
 * being used to implicitly cast ints to grids on construction.
 *
 * Can be implemented by calling Grid::Grid(width, height) constructor.
 *
 * @example
 *
 *      // Make a 16x16 grid
 *      Grid x(16);
 *
 *      // Also make a 16x16 grid
 *      Grid y = Grid(16);
 *
 *      // This should be a compiler error! We want to prevent this from being allowed.
 *      Grid z = 16;
 *
 * @param square_size
 *      The edge size to use for the width and height of the grid.
 */

Grid::Grid(int square_grid_size) : grid_width(square_grid_size), grid_height(square_grid_size),
                                   cells_arr(get_total_cells()) {
    for (int i = 0; i < get_total_cells(); ++i) {
        cells_arr[i] = Cell::DEAD;
    }
}


/**
 * Grid::Grid(width, height)
 *
 * Construct a grid with the desired size filled with dead cells.
 *
 * @example
 *
 *      // Make a 16x9 grid
 *      Grid grid(16, 9);
 *
 * @param width
 *      The width of the grid.
 *
 * @param height
 *      The height of the grid.
 */

Grid::Grid(int width, int height) : grid_width(width), grid_height(height), cells_arr(get_total_cells()) {

    for (int i = 0; i < get_total_cells(); ++i) {
        cells_arr[i] = Cell::DEAD;
    }
}

/**
 * Grid::get_width()
 *
 * Gets the current width of the grid.
 * The function should be callable from a constant context.
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Print the width of the grid to the console
 *      std::cout << grid.get_width() << std::endl;
 *
 *      // Should also be callable in a constant context
 *      const Grid &read_only_grid = grid;
 *
 *      // Print the width of the grid to the console
 *      std::cout << read_only_grid.get_width() << std::endl;
 *
 * @return
 *      The width of the grid.
 */

const int &Grid::get_width() const {
    return grid_width;
}

/**
 * Grid::get_height()
 *
 * Gets the current height of the grid.
 * The function should be callable from a constant context.
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Print the height of the grid to the console
 *      std::cout << grid.get_height() << std::endl;
 *
 *      // Should also be callable in a constant context
 *      const Grid &read_only_grid = grid;
 *
 *      // Print the height of the grid to the console
 *      std::cout << read_only_grid.get_height() << std::endl;
 *
 * @return
 *      The height of the grid.
 */

const int &Grid::get_height() const {
    return grid_height;
}

/**
 * Grid::get_total_cells()
 *
 * Gets the total number of cells in the grid.
 * The function should be callable from a constant context.
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Print the total number of cells on the grid to the console
 *      std::cout << grid.get_total_cells() << std::endl;
 *
 *      // Should also be callable in a constant context
 *      const Grid &read_only_grid = grid;
 *
 *      // Print the total number of cells on the grid to the console
 *      std::cout << read_only_grid.get_total_cells() << std::endl;
 *
 * @return
 *      The number of total cells.
 */

int Grid::get_total_cells() const {
    return grid_width * grid_height;
}

/**
 * Grid::get_alive_cells()
 *
 * Counts how many cells in the grid are alive.
 * The function should be callable from a constant context.
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Print the number of alive cells to the console
 *      std::cout << grid.get_alive_cells() << std::endl;
 *
 *      // Should also be callable in a constant context
 *      const Grid &read_only_grid = grid;
 *
 *      // Print the number of alive cells to the console
 *      std::cout << read_only_grid.get_alive_cells() << std::endl;
 *
 * @return
 *      The number of alive cells.
 */

int Grid::get_alive_cells() const {
    int count = 0;

    for (int i = 0; i < get_total_cells(); i++) {
        if (cells_arr[i] == Cell::ALIVE) {
            count++;
        }
    }
    return count;
}


/**
 * Grid::get_dead_cells()
 *
 * Counts how many cells in the grid are dead.
 * The function should be callable from a constant context.
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Print the number of dead cells to the console
 *      std::cout << grid.get_dead_cells() << std::endl;
 *
 *      // Should also be callable in a constant context
 *      const Grid &read_only_grid = grid;
 *
 *      // Print the number of dead cells to the console
 *      std::cout << read_only_grid.get_dead_cells() << std::endl;
 *
 * @return
 *      The number of dead cells.
 */

int Grid::get_dead_cells() const {
    int count = 0;

    for (int i = 0; i < get_total_cells(); ++i) {
        if (cells_arr[i] == Cell::DEAD) {
            count++;
        }
    }
    return count;
}

/**
 * Grid::resize(square_size)
 *
 * Resize the current grid to a new width and height that are equal. The content of the grid
 * should be preserved within the kept region and padded with Grid::DEAD if new cells are added.
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Resize the grid to be 8x8
 *      grid.resize(8);
 *
 * @param square_size
 *      The new edge size for both the width and height of the grid.
 */

void Grid::resize(int square_size) {
    resize(square_size, square_size);
}


/**
 * Grid::resize(width, height)
 *
 * Resize the current grid to a new width and height. The content of the grid
 * should be preserved within the kept region and padded with Grid::DEAD if new cells are added.
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Resize the grid to be 2x8
 *      grid.resize(2, 8);
 *
 * @param new_width
 *      The new width for the grid.
 *
 * @param new_height
 *      The new height for the grid.
 */

void Grid::resize(int width, int height) {

    std::vector<Cell> new_grid(width * height);

    for (int i = 0, x = 0, y = 0; i < (width * height); ++i, ++y) {

        // Simulates a 2D matrix from the 1D array used to store the data.
        if (y >= width) {
            y = 0;
            x++;
        }

        // Checks if the index is within the bounds of the old grid and keeps the value if it is.
        // If it is not it pads with DEAD cells.
        if (y < grid_width && x < grid_height) {
            if (get(x, y) == Cell::ALIVE) {
                new_grid[i] = Cell::ALIVE;
            } else {
                new_grid[i] = Cell::DEAD;
            }
        } else {
            new_grid[i] = Cell::DEAD;
        }
    }

    std::swap(cells_arr, new_grid);
    grid_height = height;
    grid_width = width;
}


/**
 * Grid::get_index(x, y)
 *
 * Private helper function to determine the 1d index of a 2d coordinate.
 * Should not be visible from outside the Grid class.
 * The function should be callable from a constant context.
 *
 * @param x
 *      The x coordinate of the cell.
 *
 * @param y
 *      The y coordinate of the cell.
 *
 * @return
 *      The 1d offset from the start of the data array where the desired cell is located.
 */

int Grid::get_index(int x, int y) const {
    int one_d_index = y * grid_width + x;
    return one_d_index;
}

/**
 * Grid::get(x, y)
 *
 * Returns the value of the cell at the desired coordinate.
 * Specifically this function should return a cell value, not a reference to a cell.
 * The function should be callable from a constant context.
 * Should be implemented by invoking Grid::operator()(x, y).
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Read the cell at coordinate (1, 2)
 *      Cell cell = grid.get(1, 2);
 *
 * @param x
 *      The x coordinate of the cell to update.
 *
 * @param y
 *      The y coordinate of the cell to update.
 *
 * @return
 *      The value of the desired cell. Should only be Grid::ALIVE or Grid::DEAD.
 *
 * @throws
 *      std::exception or sub-class if x,y is not a valid coordinate within the grid.
 */
Cell Grid::get(int x, int y) const {
    if (are_valid_other(x, y)) {
        return Cell(operator()(x, y));
    } else {
        throw std::runtime_error("Coordinates not valid.");
    }
}

/**
 * Grid::set(x, y, value)
 *
 * Overwrites the value at the desired coordinate.
 * The function should be callable from a constant context.
 * Should be implemented by invoking Grid::operator()(x, y).
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Assign to a cell at coordinate (1, 2)
 *      grid.set(1, 2, Cell::ALIVE);
 *
 * @param x
 *      The x coordinate of the cell to update.
 *
 * @param y
 *      The y coordinate of the cell to update.
 *
 * @param value
 *      The value to be written to the selected cell.
 *
 * @throws
 *      std::exception or sub-class if x,y is not a valid coordinate within the grid.
 */

void Grid::set(int x, int y, int value) {

    if (are_valid_other(x, y)) {
        operator()(x, y) = static_cast<Cell>(value);
    } else {
        throw std::runtime_error("Coordinates not valid");
    }
}

/**
 * Grid::operator()(x, y)
 *
 * Gets a modifiable reference to the value at the desired coordinate.
 * Should be implemented by invoking Grid::get_index(x, y).
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Get access to read a cell at coordinate (1, 2)
 *      Cell cell = grid(1, 2);
 *
 *      // Directly assign to a cell at coordinate (1, 2)
 *      grid(1, 2) = Cell::ALIVE;
 *
 *      // Extract a reference to an individual cell to avoid calculating it's
 *      // 1d index multiple times if you need to access the cell more than once.
 *      Cell &cell_reference = grid(1, 2);
 *      cell_reference = Cell::DEAD;
 *      cell_reference = Cell::ALIVE;
 *
 * @param x
 *      The x coordinate of the cell to access.
 *
 * @param y
 *      The y coordinate of the cell to access.
 *
 * @return
 *      A modifiable reference to the desired cell.
 *
 * @throws
 *      std::runtime_error or sub-class if x,y is not a valid coordinate within the grid.
 */

Cell &Grid::operator()(int x, int y) {

    if (are_valid_other(x, y)) {
        return cells_arr[get_index(x, y)];
    } else {
        throw std::runtime_error("Coordinates not valid");
    }
}

/**
 * Grid::operator()(x, y)
 *
 * Gets a read-only reference to the value at the desired coordinate.
 * The operator should be callable from a constant context.
 * Should be implemented by invoking Grid::get_index(x, y).
 *
 * @example
 *
 *      // Make a grid
 *      Grid grid(4, 4);
 *
 *      // Constant reference to a grid (does not make a copy)
 *      const Grid &read_only_grid = grid;
 *
 *      // Get access to read a cell at coordinate (1, 2)
 *      Cell cell = read_only_grid(1, 2);
 *
 * @param x
 *      The x coordinate of the cell to access.
 *
 * @param y
 *      The y coordinate of the cell to access.
 *
 * @return
 *      A read-only reference to the desired cell.
 *
 * @throws
 *      std::exception or sub-class if x,y is not a valid coordinate within the grid.
 */
const Cell &Grid::operator()(int x, int y) const {

    if (are_valid_other(x, y)) {
        return cells_arr[get_index(x, y)];
    } else {
        throw std::runtime_error("Coordinates are invalid.");
    }
}

/**
 * Grid::crop(x0, y0, x1, y1)
 *
 * Extract a sub-grid from a Grid.
 * The cropped grid spans the range [x0, x1) by [y0, y1) in the original grid.
 * The function should be callable from a constant context.
 *
 * @example
 *
 *      // Make a grid
 *      Grid y(4, 4);
 *
 *      // Crop the centre 2x2 in y, trimming a 1 cell border off all sides
 *      Grid x = y.crop(x, 1, 1, 3, 3);
 *
 * @param x0
 *      Left coordinate of the crop window on x-axis.
 *
 * @param y0
 *      Top coordinate of the crop window on y-axis.
 *
 * @param x1
 *      Right coordinate of the crop window on x-axis (1 greater than the largest index).
 *
 * @param y1
 *      Bottom coordinate of the crop window on y-axis (1 greater than the largest index).
 *
 * @return
 *      A new grid of the cropped size containing the values extracted from the original grid.
 *
 * @throws
 *      std::exception or sub-class if x0,y0 or x1,y1 are not valid coordinates within the grid
 *      or if the crop window has a negative size.
 */

Grid Grid::crop(int x0, int y0, int x1, int y1) const {

    // Checks if the new coordinates are within the bounds of the old grid.
    if (!are_valid_crop(x0, y0) || !are_valid_crop(x1, y1)) {
        throw std::range_error("Grid is not in the required ranges.");
    } else {

        // Sets the new grid height and weight.
        int new_grid_width = x1 - x0;
        int new_grid_height = y1 - y0;

        Grid new_grid(new_grid_width, new_grid_height);

        for (int i = 0, x = x0, y = y0, j = 0, z = 0; i < new_grid.get_total_cells(); ++i, ++x, ++j) {

            // Simulates 2D matrix from the 1D array used to store the data.
            if (x >= x1) {
                x = x0;
                j = 0;
                y++;
                z++;
            }
            new_grid(j, z) = get(x, y);
        }
        return new_grid;
    }
}

/**
 * Grid::merge(other, x0, y0, alive_only = false)
 *
 * Merge two grids together by overlaying the other on the current grid at the desired location.
 * By default merging overwrites all cells within the merge reason to be the value from the other grid.
 *
 * Conditionally if alive_only = true perform the merge such that only alive cells are updated.
 *      - If a cell is originally dead it can be updated to be alive from the merge.
 *      - If a cell is originally alive it cannot be updated to be dead from the merge.
 *
 * @example
 *
 *      // Make two grids
 *      Grid x(2, 2), y(4, 4);
 *
 *      // Overlay x as the upper left 2x2 in y
 *      y.merge(x, 0, 0);
 *
 *      // Overlay x as the bottom right 2x2 in y, reading only alive cells from x
 *      y.merge(x, 2, 2, true);
 *
 * @param other
 *      The other grid to merge into the current grid.
 *
 * @param x0
 *      The x coordinate of where to place the top left corner of the other grid.
 *
 * @param y0
 *      The y coordinate of where to place the top left corner of the other grid.
 *
 * @param alive_only
 *      Optional parameter. If true then merging only sets alive cells to alive but does not explicitly set
 *      dead cells, allowing whatever value was already there to persist. Defaults to false.
 *
 * @throws
 *      std::exception or sub-class if the other grid being placed does not fit within the bounds of the current grid.
 */

void Grid::merge(Grid grid, int x0, int y0, bool alive_only) {

    if (!are_valid_crop(x0 + grid.get_width(), y0 + grid.get_height())) {
        throw std::range_error("Grid is not in the required ranges.");
    } else {

        for (int i = 0, x = x0, y = y0, j = 0, z = 0; i < grid.get_total_cells(); ++i, ++x, ++j) {

            // Simulates 2D matrix from the 1D array used to store the data.
            if (j >= grid.get_width()) {
                x = x0;
                j = 0;
                y++;
                z++;
            }

            if (alive_only) {
                if (grid.get(j, z) == Cell::ALIVE) {
                    set(x, y, Cell::ALIVE);
                }
            } else {
                set(x, y, grid.get(j, z));
            }
        }
    }
}


/**
 * Grid::rotate(rotation)
 *
 * Create a copy of the grid that is rotated by a multiple of 90 degrees.
 * The rotation can be any integer, positive, negative, or 0.
 * The function should take the same amount of time to execute for any valid integer input.
 * The function should be callable from a constant context.
 *
 * @example
 *
 *      // Make a 1x3 grid
 *      Grid x(1,3);
 *
 *      // y is size 3x1
 *      Grid y = x.rotate(1);
 *
 * @param _rotation
 *      An positive or negative integer to rotate by in 90 intervals.
 *
 * @return
 *      Returns a copy of the grid that has been rotated.
 */

Grid Grid::rotate(int rotation) const {

    // The grid can only be in one of 4 states no matter the input. Transforms input into the correct state.
    int rotation_state = rotation % 4;

    Grid new_grid(grid_height, grid_width);

    // Changes grid dimensions based on the input.
    if (rotation_state == 2 || rotation_state == -2) {
        new_grid.resize(grid_width, grid_height);
    }

    if (rotation_state == 0) {
        return *this;
    }

    for (int i = 0, x = 0, y = 0; i < get_total_cells(); ++i, ++x) {

        // Simulates 2D matrix from the 1D array used to store the data.
        if (x >= grid_width) {
            x = 0;
            y++;
        }

        // Rearranges the grid based on the state.
        if (rotation_state == 1 || rotation_state == -3) {
            if (get(x, y) == Cell::ALIVE) {
                new_grid(grid_height - y - 1, x) = Cell::ALIVE;
            }
        } else if (rotation_state == 2 || rotation_state == -2) {
            new_grid(x, y) = cells_arr[(get_total_cells() - i) - 1];
        } else if (rotation_state == 3 || rotation_state == -1) {
            if (get(x, y) == Cell::ALIVE) {
                new_grid(y, grid_width - x - 1) = Cell::ALIVE;
            }
        }
    }
    return new_grid;
}

/**
 * operator<<(output_stream, grid)
 *
 * Serializes a grid to an ascii output stream.
 * The grid is printed wrapped in a border of - (dash), | (pipe), and + (plus) characters.
 * Alive cells are shown as # (hash) characters, dead cells with ' ' (space) characters.
 *
 * The function should be callable on a constant Grid.
 *
 * @example
 *
 *      // Make a 3x3 grid with a single alive cell
 *      Grid grid(3);
 *      grid(1, 1) = Cell::ALIVE;
 *
 *      // Print the grid to the console
 *      std::cout << grid << std::endl;
 *
 *      // The grid is printed with a border of + - and |
 *
 *      +---+
 *      |   |
 *      | # |
 *      |   |
 *      +---+
 *
 * @param os
 *
 *      An ascii mode output stream such as std::cout.
 *
 * @param grid
 *      A grid object containing cells to be printed.
 *
 * @return
 *      Returns a reference to the output stream to enable operator chaining.
 */

std::ostream &operator<<(std::ostream &stream, const Grid &grid) {

    stream << '+';
    for (int i = 0; i < grid.get_width(); ++i) {
        stream << '-';
    }
    stream << '+' << std::endl;

    for (int y = 0; y < grid.get_height(); ++y) {
        stream << '|';
        for (int x = 0; x < grid.get_width(); ++x) {
            if (grid.get(x, y) == Cell::ALIVE) {
                stream << '#';
            } else {
                stream << ' ';
            }
        }
        stream << '|' << std::endl;
    }

    stream << '+';
    for (int i = 0; i < grid.get_width(); ++i) {
        stream << '-';
    }
    stream << '+' << std::endl;

    return stream;
}

/**
 * bool::are_valid(int x, int y)
 *
 * Public helper method which is used to check if the provided coordinates x (width)
 * and y (height) are valid coordinates in the given grid.
 *
 * @example
 *
 * if(are_valid(x,y)){
 *      then ....
 *   }
 *
 *   A boolean indicating if both coordinates are valid is returned.
 *
 *   @param x
 *          The width coordinate.
 *
 *   @param y
 *          The height coordinate.
 *
 *   @return
 *         True if both coordinates are in the current grid, false otherwise.
 */

bool Grid::are_valid(int x, int y) const {
    if (x < 0 || y < 0) {
        return false;
    } else {
        return true;
    }
}

/**
 * bool::are_valid_crop(int x, int y)
 *
 * Public helper method which is used to check if the provided coordinates x (width)
 * and y (height) are valid coordinates in the given grid for the crop method.
 *
 * @example
 *
 * if(are_valid_crop(x,y)){
 *      then ....
 *   }
 *
 *   A boolean indicating if both coordinates are valid for the crop method is returned.
 *
 *   @param x
 *          The width coordinate.
 *
 *   @param y
 *          The height coordinate.
 *
 *   @return
 *         True if both coordinates are in the current grid, false otherwise.
 */

bool Grid::are_valid_crop(int x, int y) const {
    if (x > grid_width || y > grid_height) {
        return false;
    } else {
        return are_valid(x, y);
    }
}

/**
 * bool::are_valid_other(int x, int y)
 *
 * Public helper method which is used to check if the provided coordinates x (width)
 * and y (height) are valid coordinates in the given grid for all methods except crop.
 *
 * @example
 *
 * if(are_valid_other(x,y)){
 *      then ....
 *   }
 *
 *   A boolean indicating if both coordinates are valid for all methods except crop is returned.
 *
 *   @param x
 *          The width coordinate.
 *
 *   @param y
 *          The height coordinate.
 *
 *   @return
 *         True if both coordinates are in the current grid, false otherwise.
 */

bool Grid::are_valid_other(int x, int y) const {
    if (x >= grid_width || y >= grid_height) {
        return false;
    } else {
        return are_valid(x, y);
    }
}