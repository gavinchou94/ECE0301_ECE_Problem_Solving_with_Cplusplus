#ifndef _NETWORK_HPP
#define _NETWORK_HPP

#include "Node.hpp"
#include "Component.hpp"

class Network
{

private:
    /*
    Use dynamic array of Node objects. That is, nodes[i] is a Node object
    Recall that Node has get_voltage() and set_voltage(double v) methods.
    Usage example: nodes[i].set_voltage(3.3);
    */
    Node *nodes;
    int num_nodes;

    /*
    Use dynamic array of Component pointers. That is, components[i] is a pointer to a Component object
    Recall that Component has get_voltage(), get_current(), get_value(), and set_value(double v) methods.
    Usage example: components[i]->set_value(1000);
    */
    Component **components;
    int num_components;

    /*
    Private helper methods to validate node and component indices
    Only used within this class (hence private)
    */
    void check_node_idx(int idx) const;
    void check_component_idx(int idx) const;
    Node *get_node_ptr(int idx) const;

protected:
    /*
    These methods are only accessible in derived classes.
    Methods include set node voltages, connect component terminals to nodes,
    and set component values and pointers
    */
    void set_node_voltage(int idx, double val);
    void connect_component_terminal_a(int comp_idx, int node_idx);
    void connect_component_terminal_b(int comp_idx, int node_idx);
    void set_component_value(int idx, double val);
    void set_component(int idx, Component *c);

public:
    Network(int num_nodes, int num_components);
    virtual ~Network();
    int get_num_nodes() const;
    int get_num_components() const;
    double get_node_voltage(int idx) const;
    double get_component_value(int idx) const;
    double get_component_voltage(int idx) const;
    double get_component_current(int idx) const;
};

#endif