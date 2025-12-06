#include "Grid.hpp"

#include <stdexcept>
#include <algorithm>

const int Grid::DEFAULT_SIZE = 15;

Grid::Grid() : size(DEFAULT_SIZE)
{
    data = new int *[size * size];
    // initialize all to nullptr
    for (int i = 0; i < size * size; i++)
    {
        data[i] = nullptr;
    }
}

Grid::Grid(int start_size)
{
    if (start_size <= 0)
    {
        throw std::invalid_argument("Invalid grid size");
    }
    size = start_size;
    data = new int *[size * size];
    // initialize all to nullptr
    for (int i = 0; i < size * size; i++)
    {
        data[i] = nullptr;
    }
}

Grid::~Grid()
{
    clear();
    delete[] data;
}

int Grid::get_size() const
{
    return size;
}

int *Grid::get_cell(Location loc) const
{
    if (loc.row >= size || loc.col >= size)
    {
        throw std::out_of_range("Grid index out of bounds");
    }
    return data[loc.row * size + loc.col];
}

void Grid::set_cell(Location loc, int *val)
{
    if (loc.row >= size || loc.col >= size)
    {
        throw std::out_of_range("Grid index out of bounds");
    }
    int index = loc.row * size + loc.col;
    if (data[index] != nullptr)
    {
        delete data[index];
    }
    data[index] = val;
}

bool Grid::move(Location from, Location to)
{
    if (from.row >= size || from.col >= size || to.row >= size || to.col >= size)
    {
        throw std::out_of_range("Grid index out of bounds");
    }
    if (get_cell(to) != nullptr)
    {
        return false;
    }
    // get pointer to move
    int *val = get_cell(from);
    int from_index = from.row * size + from.col;
    int to_index = to.row * size + to.col;
    // move pointer
    data[to_index] = val;
    data[from_index] = nullptr;
    return true;
}

void Grid::clear()
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            set_cell(Location{r, c}, nullptr);
        }
    }
}

void Grid::resize(int new_size)
{
    if (new_size <= 0)
    {
        throw std::invalid_argument("Invalid grid size");
    }
    // deallocate current items in grid
    clear();

    // allocate new and swap
    int **new_grid = new int *[new_size * new_size];
    for (int i = 0; i < new_size * new_size; i++)
    {
        new_grid[i] = nullptr;
    }

    std::swap(data, new_grid);

    size = new_size;

    // deallocate other grid
    delete[] new_grid;
}
