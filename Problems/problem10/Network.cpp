#include "Network.hpp"

#include <stdexcept>

/*
Constructor: creates nodes and components
They are uninitialized (0V for all nodes, nullptr for all components)
None of the nodes or components are connected
*/
Network::Network(int num_nodes, int num_components)
{
    if (num_nodes < 0)
    {
        throw std::invalid_argument("Number of nodes cannot be negative");
    }
    if (num_components < 0)
    {
        throw std::invalid_argument("Number of components cannot be negative");
    }
    this->num_nodes = num_nodes;
    this->num_components = num_components;
    nodes = new Node[num_nodes];
    components = new Component *[num_components];
    for (int i = 0; i < num_components; i++)
    {
        components[i] = nullptr;
    }
}

/*
Destructor: deallocates dynamic arrays
Also deallocates each Component object pointed to by components array
*/
Network::~Network()
{
    delete[] nodes;
    for (int i = 0; i < num_components; i++)
    {
        delete components[i];
    }
    delete[] components;
}

int Network::get_num_nodes() const
{
    return num_nodes;
}

int Network::get_num_components() const
{
    return num_components;
}

double Network::get_node_voltage(int idx) const
{
    check_node_idx(idx); // validate index and throw exception if invalid
    // nodes[i] is a Node object
    // use . to access Node methods
    return nodes[idx].get_voltage();
}

double Network::get_component_value(int idx) const
{
    check_component_idx(idx); // validate index and throw exception if invalid
    // components[i] is a pointer to Component object
    // use *(x).y to access Component methods, that's ->
    return components[idx]->get_value();
}

double Network::get_component_voltage(int idx) const
{
    check_component_idx(idx);
    return components[idx]->get_voltage();
}

double Network::get_component_current(int idx) const
{
    check_component_idx(idx);
    return components[idx]->get_current();
}

Node *Network::get_node_ptr(int idx) const
{
    check_node_idx(idx);
    return &nodes[idx];
}

void Network::set_node_voltage(int idx, double val)
{
    check_node_idx(idx);
    nodes[idx].set_voltage(val);
}

void Network::connect_component_terminal_a(int comp_idx, int node_idx)
{
    check_component_idx(comp_idx); // validate component index
    check_node_idx(node_idx);      // validate node index
    components[comp_idx]->set_node_a(get_node_ptr(node_idx));
}

void Network::connect_component_terminal_b(int comp_idx, int node_idx)
{
    check_component_idx(comp_idx); // validate component index
    check_node_idx(node_idx);      // validate node index
    components[comp_idx]->set_node_b(get_node_ptr(node_idx));
}

void Network::set_component_value(int idx, double val)
{
    check_component_idx(idx);
    components[idx]->set_value(val);
}

void Network::set_component(int idx, Component *c)
{
    check_component_idx(idx);
    delete components[idx];
    components[idx] = c;
}

void Network::check_node_idx(int idx) const
{
    if (idx < 0 || idx >= num_nodes)
    {
        throw std::out_of_range("Node index out of range");
    }
}

void Network::check_component_idx(int idx) const
{
    if (idx < 0 || idx >= num_components)
    {
        throw std::out_of_range("Component index out of range");
    }
}
