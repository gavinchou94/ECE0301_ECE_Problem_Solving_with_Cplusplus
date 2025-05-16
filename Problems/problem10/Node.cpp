#include "Node.hpp"

Node::Node() : voltage(0)
{
}

Node::Node(double v) : voltage(v)
{
}

double Node::get_voltage() const
{
    return voltage;
}

void Node::set_voltage(double v)
{
    voltage = v;
}
