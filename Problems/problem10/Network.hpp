#ifndef _NETWORK_HPP
#define _NETWORK_HPP

#include "Node.hpp"
#include "Component.hpp"

class Network {

    private:
        Node* nodes;
        int num_nodes;
        Component** components; // using a dynamic array of pointers to enable dynamic binding
        int num_components;
        void check_node_idx(int idx) const;
        void check_component_idx(int idx) const;
        Node* get_node_ptr(int idx) const;

    protected:
        // these methods are only accessible in derived classes
        void set_node_voltage(int idx, double val);
        void connect_component_terminal_a(int comp_idx, int node_idx);
        void connect_component_terminal_b(int comp_idx, int node_idx);
        void set_component_value(int idx, double val);
        void set_component(int idx, Component* c);

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