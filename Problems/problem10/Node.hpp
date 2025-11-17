#ifndef _NODE_HPP
#define _NODE_HPP

class Node
{
private:
    double voltage;

public:
    Node();
    Node(double v);
    double get_voltage() const;
    void set_voltage(double v);
};

#endif