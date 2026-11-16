#ifndef NETWORK_HPP
#define NETWORK_HPP

// Circuit visualizer copy of Network.hpp (provided, do not edit; not graded).
// Same interface as the Problem 10 starter code, plus two read-only dbg_ methods
// that let the visualizer see which nodes each component is connected to.
// The mutators also print a TRACE line so a constructor that throws can still be drawn.

#include "Node.hpp"
#include "Component.hpp"

class Network
{

private:
    Node *nodes;
    int num_nodes;
    Component **components;
    int num_components;

    void check_node_idx(int idx) const;
    void check_component_idx(int idx) const;
    Node *get_node_ptr(int idx) const;

protected:
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

    // visualizer only (not part of the assignment)
    const Component *dbg_component(int idx) const; // nullptr if out of range or never created
    int dbg_node_index(const Node *p) const;       // -1 if nullptr, -2 if not a node of this network
};

#endif