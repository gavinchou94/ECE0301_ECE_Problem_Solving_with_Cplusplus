#include "Network.hpp"

#include <cstdio>
#include <stdexcept>
#include <string>
#include <typeinfo>

// Circuit visualizer copy of Network.cpp (provided, do not edit; not graded).
// Same behavior as the starter code, with
// (1) a TRACE line printed by every mutator, and
// (2) a std::logic_error instead of a crash when a component was never created.

namespace
{
    std::string clean(const char *s)
    {
        std::string out(s);
        for (std::size_t i = 0; i < out.size(); i++)
        {
            if (out[i] == '\t' || out[i] == '\n' || out[i] == '\r')
            {
                out[i] = ' ';
            }
        }
        return out;
    }
    void trace_ok()
    {
        std::printf("\tok\n");
        std::fflush(stdout);
    }
    void trace_err(const std::exception &e)
    {
        std::printf("\t!%s\n", clean(e.what()).c_str());
        std::fflush(stdout);
    }
}

Network::Network(int num_nodes, int num_components)
{
    std::printf("TRACE\tnetwork\t%d\t%d\n", num_nodes, num_components);
    std::fflush(stdout);
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
    check_node_idx(idx);
    return nodes[idx].get_voltage();
}

double Network::get_component_value(int idx) const
{
    check_component_idx(idx);
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
    std::printf("TRACE\tset_node_voltage\t%d\t%.15g", idx, val);
    try
    {
        check_node_idx(idx);
        nodes[idx].set_voltage(val);
    }
    catch (const std::exception &e)
    {
        trace_err(e);
        throw;
    }
    trace_ok();
}

void Network::connect_component_terminal_a(int comp_idx, int node_idx)
{
    std::printf("TRACE\tconnect_a\t%d\t%d", comp_idx, node_idx);
    try
    {
        check_component_idx(comp_idx);
        check_node_idx(node_idx);
        components[comp_idx]->set_node_a(get_node_ptr(node_idx));
    }
    catch (const std::exception &e)
    {
        trace_err(e);
        throw;
    }
    trace_ok();
}

void Network::connect_component_terminal_b(int comp_idx, int node_idx)
{
    std::printf("TRACE\tconnect_b\t%d\t%d", comp_idx, node_idx);
    try
    {
        check_component_idx(comp_idx);
        check_node_idx(node_idx);
        components[comp_idx]->set_node_b(get_node_ptr(node_idx));
    }
    catch (const std::exception &e)
    {
        trace_err(e);
        throw;
    }
    trace_ok();
}

void Network::set_component_value(int idx, double val)
{
    std::printf("TRACE\tset_component_value\t%d\t%.15g", idx, val);
    try
    {
        check_component_idx(idx);
        components[idx]->set_value(val);
    }
    catch (const std::exception &e)
    {
        trace_err(e);
        throw;
    }
    trace_ok();
}

void Network::set_component(int idx, Component *c)
{
    std::printf("TRACE\tset_component\t%d\t%s", idx, c == nullptr ? "nullptr" : typeid(*c).name());
    try
    {
        if (idx < 0 || idx >= num_components)
        {
            throw std::out_of_range("Component index out of range");
        }
    }
    catch (const std::exception &e)
    {
        trace_err(e);
        throw;
    }
    delete components[idx];
    components[idx] = c;
    trace_ok();
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
    if (components[idx] == nullptr)
    {
        // the starter code would dereference a null pointer here and crash
        throw std::logic_error("Component " + std::to_string(idx) + " was never created with set_component (the starter Network would crash here)");
    }
}

const Component *Network::dbg_component(int idx) const
{
    if (idx < 0 || idx >= num_components)
    {
        return nullptr;
    }
    return components[idx];
}

int Network::dbg_node_index(const Node *p) const
{
    if (p == nullptr)
    {
        return -1;
    }
    for (int i = 0; i < num_nodes; i++)
    {
        if (&nodes[i] == p)
        {
            return i;
        }
    }
    return -2;
}