/**
 * Implements a Zoo namespace with methods for constructing Grid objects containing various creatures in the Game of Life.
 *      - Creatures like gliders, light weight spaceships, and r-pentominos can be spawned.
 *          - These creatures are drawn on a Grid the size of their bounding box.
 *
 *      - Grids can be loaded from and saved to an ascii file format.
 *          - Ascii files are composed of:
 *              - A header line containing an integer width and height separated by a space.
 *              - followed by (height) number of lines, each containing (width) number of characters,
 *                terminated by a newline character.
 *              - (space) ' ' is Cell::DEAD, (hash) '#' is Cell::ALIVE.
 *
 *      - Grids can be loaded from and saved to an binary file format.
 *          - Binary files are composed of:
 *              - a 4 byte int representing the grid width
 *              - a 4 byte int representing the grid height
 *              - followed by (width * height) number of individual bits in C-style row/column format,
 *                padded with zero or more 0 bits.
 *              - a 0 bit should be considered Cell::DEAD, a 1 bit should be considered Cell::ALIVE.
 *
 * @author 958753
 * @date March, 2020
 */
#include <fstream>
#include <sys/stat.h>
#include <bitset>
#include "zoo.h"
#include "grid.h"


// Include the minimal number of headers needed to support your implementation.
// #include ...

/**
 * Zoo::glider()
 *
 * Construct a 3x3 grid containing a glider.
 * https://www.conwaylife.com/wiki/Glider
 *
 * @example
 *
 *      // Print a glider in a Grid the size of its bounding box.
 *      std::cout << Zoo::glider() << std::endl;
 *
 *      +---+
 *      | # |
 *      |  #|
 *      |###|
 *      +---+
 *
 * @return
 *      Returns a Grid containing a glider.
 */

Grid Zoo::glider() {
    Grid glider(3);
    glider.set(1, 0, Cell::ALIVE);
    glider.set(2, 1, Cell::ALIVE);
    glider.set(0, 2, Cell::ALIVE);
    glider.set(1, 2, Cell::ALIVE);
    glider.set(2, 2, Cell::ALIVE);
    return glider;
}

/**
 * Zoo::r_pentomino()
 *
 * Construct a 3x3 grid containing an r-pentomino.
 * https://www.conwaylife.com/wiki/R-pentomino
 *
 * @example
 *
 *      // Print an r-pentomino in a Grid the size of its bounding box.
 *      std::cout << Zoo::r_pentomino() << std::endl;
 *
 *      +---+
 *      | ##|
 *      |## |
 *      | # |
 *      +---+
 *
 * @return
 *      Returns a Grid containing a r-pentomino.
 */

Grid Zoo::r_pentomino() {
    Grid r_pentomino(3);

    r_pentomino.set(1, 0, Cell::ALIVE);
    r_pentomino.set(2, 0, Cell::ALIVE);
    r_pentomino.set(0, 1, Cell::ALIVE);
    r_pentomino.set(1, 1, Cell::ALIVE);
    r_pentomino.set(1, 2, Cell::ALIVE);

    return r_pentomino;
}

/**
 * Zoo::light_weight_spaceship()
 *
 * Construct a 5x4 grid containing a light weight spaceship.
 * https://www.conwaylife.com/wiki/Lightweight_spaceship
 *
 * @example
 *
 *      // Print a light weight spaceship in a Grid the size of its bounding box.
 *      std::cout << Zoo::light_weight_spaceship() << std::endl;
 *
 *      +-----+
 *      | #  #|
 *      |#    |
 *      |#   #|
 *      |#### |
 *      +-----+
 *
 * @return
 *      Returns a grid containing a light weight spaceship.
 */

Grid Zoo::light_weight_spaceship() {
    Grid light_weight_spaceship(5, 4);

    light_weight_spaceship.set(1, 0, Cell::ALIVE);
    light_weight_spaceship.set(4, 0, Cell::ALIVE);
    light_weight_spaceship.set(0, 1, Cell::ALIVE);
    light_weight_spaceship.set(0, 2, Cell::ALIVE);
    light_weight_spaceship.set(4, 2, Cell::ALIVE);
    for (int i = 0; i < 4; ++i) {
        light_weight_spaceship.set(i, 3, Cell::ALIVE);
    }

    return light_weight_spaceship;
}

/**
 * Zoo::load_ascii(path)
 *
 * Load an ascii file and parse it as a grid of cells.
 * Should be implemented using std::ifstream.
 *
 * @example
 *
 *      // Load an ascii file from a directory
 *      Grid grid = Zoo::load_ascii("path/to/file.gol");
 *
 * @param path
 *      The std::string path to the file to read in.
 *
 * @return
 *      Returns the parsed grid.
 *
 * @throws
 *      Throws std::runtime_error or sub-class if:
 *          - The file cannot be opened.
 *          - The parsed width or height is not a positive integer.
 *          - Newline characters are not found when expected during parsing.
 *          - The character for a cell is not the ALIVE or DEAD character.
 */

Grid Zoo::load_ascii(std::string path) {

    std::ifstream inFile(path);

    if (!inFile.is_open()) {
        throw std::invalid_argument("File not found.");
    }

    int width;
    int height;
    char character;

    inFile >> width;
    inFile >> height;

    if (width < 0 || height < 0) {
        inFile.close();
        throw std::invalid_argument("Width or height less than 0.");
    }

    inFile.get(character);

    if (character != '\n' && character != '\r' && character != '\000') {
        inFile.close();
        throw std::invalid_argument("Malformed newline.");
    }

    Grid grid(width, height);
    char line[width + 1];

    for (int i = 0, x = 0, y = 0; i < grid.get_height(); ++i) {
        inFile.getline(line, grid.get_width() + 1);

        for (int j = 0; j < grid.get_width(); ++j) {

            if (line[j] != char(Cell::DEAD) && line[j] != char(Cell::ALIVE)) {
                inFile.close();
                throw std::invalid_argument("Incorrect cell value.");
            }

            if (line[j] == char(Cell::ALIVE)) {
                grid.set(x, y, Cell::ALIVE);
            }

            x++;
        }

        if (line[width + 1] != '\n' && line[width + 1] != '\r' && line[width + 1] != '\000') {
            inFile.close();
            throw std::invalid_argument("Malformed newline.");
        }
        x = 0;
        y++;
    }
    inFile.close();
    return grid;
}

/**
 * Zoo::save_ascii(path, grid)
 *
 * Save a grid as an ascii .gol file according to the specified file format.
 * Should be implemented using std::ofstream.
 *
 * @example
 *
 *      // Make an 8x8 grid
 *      Grid grid(8);
 *
 *      // Save a grid to an ascii file in a directory
 *      try {
 *          Zoo::save_ascii("path/to/file.gol", grid);
 *      }
 *      catch (const std::exception &ex) {
 *          std::cerr << ex.what() << std::endl;
 *      }
 *
 * @param path
 *      The std::string path to the file to write to.
 *
 * @param grid
 *      The grid to be written out to file.
 *
 * @throws
 *      Throws std::runtime_error or sub-class if the file cannot be opened.
 */

void Zoo::save_ascii(std::string path, Grid grid) {
    std::ofstream outFile(path);
    if (!outFile.is_open()) {
        throw std::invalid_argument("No such path");
    }
    outFile << grid.get_width() << " ";
    outFile << grid.get_height() << std::endl;

    for (int y = 0; y < grid.get_height(); ++y) {
        for (int x = 0; x < grid.get_width(); ++x) {
            outFile << char(grid.get(x, y));
        }
        outFile << std::endl;
    }
}


/**
 * Zoo::load_binary(path)
 *
 * Load a binary file and parse it as a grid of cells.
 * Should be implemented using std::ifstream.
 *
 * @example
 *
 *      // Load an binary file from a directory
 *      Grid grid = Zoo::load_binary("path/to/file.bgol");
 *
 * @param path
 *      The std::string path to the file to read in.
 *
 * @return
 *      Returns the parsed grid.
 *
 * @throws
 *      Throws std::runtime_error or sub-class if:
 *          - The file cannot be opened.
 *          - The file ends unexpectedly.
 */

Grid Zoo::load_binary(std::string path) {

    std::ifstream in_file(path, std::ios::binary);

    if (!in_file.is_open()) {
        throw std::invalid_argument("File not found");
    }

//    using byte = unsigned char;
//    constexpr std::size_t BITS_PER_BYTE = std::numeric_limits<byte>::digits;
    using bits_in_byte = std::bitset<8>;

    int width;
    in_file.read(reinterpret_cast<char *>(&width), 4);
    int height;
    in_file.read(reinterpret_cast<char *>(&height), 4);

    Grid grid(width, height);

    std::string bit_string;
    char c;

    while (in_file.get(c)) {
        std::string temp;
        temp = bits_in_byte(c).to_string();
        std::reverse(temp.begin(), temp.end());
        bit_string += temp;
    }

    if (int(bit_string.length()) < grid.get_total_cells()) {
        throw std::invalid_argument("Malformed file.");
    }

    for (int j = 0, x = 0, y = 0; j < grid.get_total_cells(); ++j, ++x) {

        if (x >= grid.get_width()) {
            x = 0;
            ++y;
        }

        if (bit_string[j] == '1') {
            grid.set(x, y, Cell::ALIVE);
        } else {
            grid.set(x, y, Cell::DEAD);
        }
    }
    in_file.close();
    return grid;
}

/**
 * Zoo::save_binary(path, grid)
 *
 * Save a grid as an binary .bgol file according to the specified file format.
 * Should be implemented using std::ofstream.
 *
 * @example
 *
 *      // Make an 8x8 grid
 *      Grid grid(8);
 *
 *      // Save a grid to an binary file in a directory
 *      try {
 *          Zoo::save_binary("path/to/file.bgol", grid);
 *      }
 *      catch (const std::exception &ex) {
 *          std::cerr << ex.what() << std::endl;
 *      }
 *
 * @param path
 *      The std::string path to the file to write to.
 *
 * @param grid
 *      The grid to be written out to file.
 *
 * @throws
 *      Throws std::runtime_error or sub-class if the file cannot be opened.
 */

void Zoo::save_binary(std::string path, Grid grid) {
    std::ofstream out_file(path, std::ios::binary);

    if (!out_file.is_open()) {
        throw std::invalid_argument("No such path.");
    }

//    using byte = unsigned char;
//    constexpr std::size_t BITS_PER_BYTE = std::numeric_limits<byte>::digits;
    using bits_in_byte = std::bitset<8>;


    out_file.write(reinterpret_cast<const char *>(&grid.get_width()), 4);
    out_file.write(reinterpret_cast<const char *>(&grid.get_height()), 4);


    std::string temp;
    for (int i = 0, x = 0, y = 0; i < grid.get_total_cells(); ++i, ++x) {
        if (x >= grid.get_width()) {
            x = 0;
            ++y;
        }

        if (grid.get(x, y) == Cell::ALIVE) {
            temp += '1';
        } else {
            temp += '0';
        }

        if ((i + 1) % 8 == 0) {
            std::reverse(temp.begin(), temp.end());
            char cur_char = bits_in_byte(temp).to_ulong();
            out_file.write((char *) &cur_char, sizeof(char));
            temp.clear();
        }
    }

    if (grid.get_total_cells() % 8 != 0) {
        std::reverse(temp.begin(), temp.end());
        char cur_char = bits_in_byte(temp).to_ulong();
        out_file.write((char *) &cur_char, sizeof(char));
    }
    out_file.close();
}
