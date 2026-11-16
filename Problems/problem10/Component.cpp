#include "Component.hpp"

#include <stdexcept>

Component::Component(double val, Node *A, Node *B) : nodeAptr(A), nodeBptr(B), value(val)
{
}

Component::Component(Node *A, Node *B) : nodeAptr(A), nodeBptr(B), value(0)
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
  // Allow both terminals to be nullptr. Reject matching non-null nodes.
  if (A == nodeBptr && nodeBptr != nullptr)
  {
    throw std::invalid_argument("Node pointers cannot be equal");
  }
  nodeAptr = A;
}

void Component::set_node_b(Node *B)
{
  // Allow both terminals to be nullptr. Reject matching non-null nodes.
  if (B == nodeAptr && nodeAptr != nullptr)
  {
    throw std::invalid_argument("Node pointers cannot be equal");
  }
  nodeBptr = B;
}

double Component::get_voltage() const
{
  if (nodeAptr == nullptr || nodeBptr == nullptr)
  {
    throw std::logic_error("Component terminal(s) not connected");
  }
  // Voltage is defined as terminal B minus terminal A.
  return nodeBptr->get_voltage() - nodeAptr->get_voltage();
}

double Component::get_current() const
{
  // Derived classes can override this default.
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