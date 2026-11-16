// This is SafeArray3.hpp
// Changes from SafeArray2.hpp:
// - Makes set() virtual so derived classes can override it.
// - Makes the destructor virtual so deletion through a base pointer is safe.
// - Temporarily makes the data members protected for the demonstration.

#ifndef SAFE_ARRAY_HPP
#define SAFE_ARRAY_HPP

class SafeArray
{
protected: // temp change to protected
  int *dataptr;
  int size;

public:
  SafeArray();
  SafeArray(int);
  virtual ~SafeArray(); // has to include this due to dataptr; virtual for deleting through a base pointer

  // this is copy constructor
  SafeArray(const SafeArray &);

  // this is copy assignment
  SafeArray &operator=(SafeArray);

  int get_size() const;
  int get(int) const;         // change [] to get() for SafeArray object to access
  virtual void set(int, int); // change [] to set( , ) for SafeArray object to update
};

SafeArray operator+(const SafeArray &, int); // pass by const reference
SafeArray operator+(int, const SafeArray &); // pass by const reference

#endif