#ifndef _AGENT_HPP
#define _AGENT_HPP

enum AgentType {NONE, ACORN, SQUL, FOX};
enum Direction {LEFT, RIGHT, UP, DOWN};

/* Agent interface: Do not modify */
class Agent {
    public:
        virtual ~Agent() {}; 
        virtual AgentType get_type() const = 0;
        virtual int get_energy() const = 0;
        virtual void energize(int e) = 0;
        virtual Direction action() const = 0;
        virtual Direction next_action() = 0;
        virtual bool can_act() const = 0;
        virtual bool act() = 0;
};

#endif