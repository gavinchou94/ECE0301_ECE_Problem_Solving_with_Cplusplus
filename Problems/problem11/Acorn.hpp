#ifndef _ACORN_HPP
#define _ACORN_HPP

#include "Agent.hpp"

class Acorn : public Agent {
    private:

    public:
        static const int PHOTO_ENERGY;
        static const int GROW_ENERGY;
        static const int MOVES;
        
        // TODO
        Acorn();
        Acorn(int e);
        AgentType get_type() const;
        int get_energy() const;
        void energize(int e);
        Direction action() const;
        Direction next_action();
        bool can_act() const;
        bool act();    
};

#endif