#ifndef _SIMULATOR_HPP
#define _SIMULATOR_HPP

#include <string>

#include "Grid.hpp"
#include "Agent.hpp"
#include "Acorn.hpp"
#include "Squirrel.hpp"
#include "Fox.hpp"

class Simulator
{
public:
    Simulator();
    Simulator(int start_size);
    int size() const;
    AgentType get_type(Location loc) const;
    bool set(Location loc, AgentType atype);
    bool remove(Location loc);
    void clear();
    bool energize(Location loc, int energy);
    void update();
    bool done() const;
    bool export_image(std::string outfile);
    bool export_animation(std::string outfile, int steps);

private:
    Grid simgrid;
    Location loc_from_direction(Location loc, Direction dir);
    void update_acorn(Location loc);
    void update_squirrel(Location loc);
    void update_fox(Location loc);
};

#endif