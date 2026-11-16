#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Node.hpp"

class Component
{
private:
  Node *nodeAptr;
  Node *nodeBptr;
  double value;

public:
  Component(Node *A, Node *B);

  /*
  Initializes the component value and the node pointers for terminals A and B.
  With no arguments, the value is 0 and both pointers are nullptr.
  */
  Component(double val = 0, Node *A = nullptr, Node *B = nullptr);

  /*
  The destructor has nothing to deallocate, because we do not consider the Node to “belong to”
  the Component. Deallocation will be the responsibility of the test case or network that
  creates the nodes and passes the pointers to the Component.
  It is virtual so that a derived object can be safely deleted through a Component pointer,
  as Network does with "delete components[i];"
  */
  virtual ~Component() = default;

  /*
  Get methods for the Node pointers
  */
  Node *get_node_a() const;
  Node *get_node_b() const;

  /*
  Set methods check that the Node pointers are not identical (unless both are nullptr),
  For example, if Node pointer A is currently 0x001, and set_node_b(0x001) is called, the
  function will throw std::invalid_argument.
  */
  void set_node_a(Node *A);
  void set_node_b(Node *B);

  /*
  get_voltage accesses the Node pointers and returns the voltage difference terminal B - terminal A.
  If either terminal is nullptr, throws std::logic_error.
  It will be overridden in derived classes based on component type.
  */
  virtual double get_voltage() const;

  /*
  get_current is a virtual function that returns 0.0 in the base class.
  It will be overridden in derived classes based on component type.
  */
  virtual double get_current() const;

  /*
  Get and set methods for the component value
  */
  double get_value() const;
  virtual void set_value(double newval);
};

#endif