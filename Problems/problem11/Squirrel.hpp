#ifndef _SQUL_HPP
#define _SQUL_HPP

#include "Agent.hpp"

class Squirrel : public Agent
{

private:
public:
    static const int MOVES;
    static const int MOVE_ENERGY;

    // TODO
    Squirrel();
    Squirrel(int e);
    AgentType get_type() const;
    int get_energy() const;
    void energize(int e);
    Direction action() const;
    Direction next_action();
    bool can_act() const;
    bool act();
};

#endif