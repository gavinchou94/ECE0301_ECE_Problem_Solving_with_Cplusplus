#include "Fox.hpp"

const int Fox::MOVES = 4;
const int Fox::MOVE_ENERGY = 7;

// BONUS

Fox::Fox() 
{
}

Fox::Fox(int start_energy) 
{
}

AgentType Fox::get_type() const
{
    return NONE;
}

int Fox::get_energy() const
{
    return 0;
}

void Fox::energize(int e)
{
}

Direction Fox::action() const
{
    return RIGHT;
}

Direction Fox::next_action()
{
    return RIGHT;
}


bool Fox::can_act() const
{
    return false;
}

bool Fox::act()
{
    return false;
}