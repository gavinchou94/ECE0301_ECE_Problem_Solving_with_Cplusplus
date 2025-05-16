#ifndef _FOX_HPP
#define _FOX_HPP

#include "Agent.hpp"

// BONUS

class Fox : public Agent {
    private:

    public:
        static const int MOVES;
        static const int MOVE_ENERGY;
        Fox();
        Fox(int start_energy);
        AgentType get_type() const;
        int get_energy() const;
        void energize(int e);
        Direction action() const;
        Direction next_action();
        bool can_act() const;
        bool act();
        Direction dir_decode(int dir_index) const;
};

#endif