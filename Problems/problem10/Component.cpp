#include "Component.hpp"

#include <stdexcept>

Component::Component(double val, Node *A, Node *B) : value(val), nodeAptr(A), nodeBptr(B)
{
}

Component::Component(Node *A, Node *B) : value(0), nodeAptr(A), nodeBptr(B)
{
}

Node *Component::get_node_a() const
{
    return nodeAptr;
}

Node *Component::get_node_b() const
{
    return nodeBptr;
}

void Component::set_node_a(Node *A)
{
    // do not set node A the same as node B
    // but allow setting both to nullptr
    if (A ==  nodeBptr && nodeBptr != nullptr) {
        throw std::invalid_argument("Node pointers cannot be equal");
    }
    nodeAptr = A;
}

void Component::set_node_b(Node *B)
{
    // do not set node B the same as node A
    // but allow setting both to nullptr
    if (B == nodeAptr && nodeAptr != nullptr) {
        throw std::invalid_argument("Node pointers cannot be equal");
    }
    nodeBptr = B;
}

double Component::get_voltage() const
{
    if (nodeAptr == nullptr || nodeBptr == nullptr) {
        throw std::logic_error("Component terminal(s) not connected");
    }
    // voltage is defined as node B - node A
    return nodeBptr->get_voltage() - nodeAptr->get_voltage();
}

double Component::get_current() const
{
    // will be implemented in derived classes
    return 0.0;
}

double Component::get_value() const
{
    return value;
}

void Component::set_value(double newval)
{
    value = newval;
}
