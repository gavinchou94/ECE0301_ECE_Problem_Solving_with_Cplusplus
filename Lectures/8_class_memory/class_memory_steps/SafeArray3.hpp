// This is SafeArray3.hpp
// Changes from SafeArray2.hpp:
// - Adds a copy constructor.
// - Explains when passing by value calls the copy constructor.

#ifndef SAFE_ARRAY_HPP
#define SAFE_ARRAY_HPP

class SafeArray
{
private:
  int *dataptr;
  int size;

public:
  SafeArray();
  SafeArray(int);
  ~SafeArray(); // The destructor frees the array allocated by dataptr.

  // Copy constructor.
  SafeArray(const SafeArray &);
  // A copy constructor takes a const reference to an object of the same class.

  // Side note:
  // Passing an object by value calls the copy constructor.
  // For example, passing c1 to function1(Class c) creates a copy of c1:
  // this is equivalent to Class c(c1).

  int get_size() const;
  int operator[](int) const; // Read an element using [].
  int &operator[](int);      // Return an element by reference so it can be modified using [].
};

#endif