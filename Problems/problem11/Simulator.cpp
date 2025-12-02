#include "Simulator.hpp"

#include "bitmap.hpp"
#include "gif.h"
#include <vector>

/* Helper methods */
Location Simulator::loc_from_direction(Location loc, Direction dir)
{
    Location newloc = loc;
    switch (dir)
    {
    case LEFT:
        newloc.col--;
        break;
    case UP:
        newloc.row--;
        break;
    case RIGHT:
        newloc.col++;
        break;
    case DOWN:
        newloc.row++;
    }
    return newloc;
}

void Simulator::update_acorn(Location loc)
{
    // TODO
}

void Simulator::update_squirrel(Location loc)
{
    // TODO
}

void Simulator::update_fox(Location loc)
{
    // TODO
}

/* Public members */

Simulator::Simulator()
{
}

Simulator::Simulator(int start_size)
{
    simgrid.resize(start_size); // Grid should throw with invalid size
}

int Simulator::size() const
{
    return simgrid.get_size();
}

AgentType Simulator::get_type(Location loc) const
{
    // TODO
}

bool Simulator::set(Location loc, AgentType atype)
{
    // TODO: Implement the set method, which places an agent of the given type at the given location.

    // If the location is already occupied, the method should return false.
    // Otherwise, it should return true, and place the agent at the location.
    // Hint: You can use the get_cell and set_cell methods of the Grid class.
    // An agent of the given type can be created using the new operator.
}

bool Simulator::remove(Location loc)
{
    if (get_type(loc) == NONE)
    {
        return false;
    }
    simgrid.set_cell(loc, nullptr);
    return true;
}

void Simulator::clear()
{
    simgrid.clear();
}

bool Simulator::energize(Location loc, int energy)
{
    if (simgrid.get_cell(loc) == nullptr)
    {
        return false;
    }
    simgrid.get_cell(loc)->energize(energy);
    return true;
}

void Simulator::update()
{
    int size = simgrid.get_size();
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            Location loc{r, c};
            AgentType type = get_type(loc);
            switch (type)
            {
            case ACORN:
                update_acorn(loc);
                break;
            case SQUL:
                update_squirrel(loc);
                break;
            case FOX:
                update_fox(loc);
                break;
            case NONE:
                break;
            }
        }
    }
}

bool Simulator::done() const
{
    // TODO
}

bool Simulator::export_image(std::string outfile)
{
    int size = simgrid.get_size();
    RGBPIXEL *image_data = new RGBPIXEL[size * size];

    AgentType type;
    int index;
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            type = get_type(Location{r, c});
            index = r * size + c;
            switch (type)
            {
            case ACORN:
                image_data[index] = GOLD;
                break;
            case SQUL:
                image_data[index] = BLUE;
                break;
            case FOX:
                image_data[index] = GRAY;
                break;
            case NONE:
                if ((r + c) % 2 == 0)
                {
                    image_data[index] = WHITE;
                }
                else
                {
                    image_data[index] = BLACK;
                }
                break;
            }
        }
    }

    RGBIMAGEDATA export_data{image_data, size, size};
    bool success = export_bmp(export_data, outfile);

    delete[] image_data;

    return success;
}

bool Simulator::export_animation(std::string outfile, int steps)
// Bonus test: mimic the sample gif animation in testing cases by looking at the initial configuration
// Bonus modification of export_animation: color gradient based on energy levels
{
    int steps_per_frame = 1; // Number of steps to update per frame
    int delay = 100;         // Delay between frames in hundredths of a second

    int size = simgrid.get_size();

    GifWriter gif;
    if (!GifBegin(&gif, (outfile + ".gif").c_str(), size, size, delay))
    {
        return false;
    }

    for (int i = 0; i < steps; ++i)
    {

        // Generate or update image data for the current frame
        RGBPIXEL *image_data = new RGBPIXEL[size * size];

        AgentType type;
        int index;
        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                type = get_type(Location{r, c});
                index = r * size + c;
                switch (type)
                {
                case ACORN:
                    image_data[index] = GOLD;
                    break;
                case SQUL:
                    image_data[index] = BLUE;
                    break;
                case FOX:
                    image_data[index] = GRAY;
                    break;
                case NONE:
                    if ((r + c) % 2 == 0)
                    {
                        image_data[index] = WHITE;
                    }
                    else
                    {
                        image_data[index] = BLACK;
                    }
                    break;
                }
            }
        }

        // Convert image_data to RGB format
        std::vector<uint8_t> rgb_data(size * size * 4);
        for (int j = 0; j < size * size; ++j)
        {
            rgb_data[j * 4 + 0] = image_data[j].red;
            rgb_data[j * 4 + 1] = image_data[j].green;
            rgb_data[j * 4 + 2] = image_data[j].blue;
        }

        // Write the current frame to the GIF
        if (!GifWriteFrame(&gif, rgb_data.data(), size, size, delay))
        {
            GifEnd(&gif);
            return false;
        }

        // Update objects
        for (int step = 0; step < steps_per_frame; ++step)
        {
            // Update objects logic here
            update();
        }
    }

    GifEnd(&gif);
    return true;
}
