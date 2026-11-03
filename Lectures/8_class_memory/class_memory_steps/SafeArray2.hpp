// This is SafeArray2.hpp
// Changes from SafeArray1.hpp:
// - Adds operator[] for reading.
// - Adds operator[] for writing.

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

  int get_size() const;
  int operator[](int) const; // Read an element using [].
  int &operator[](int);      // Return an element by reference so it can be modified using [].
};

#endif

// Notes on int &operator[](int):

// The first "int" is the element type returned by reference.
// "&" means the function returns a reference, which can be used on the left side of an assignment.
// operator[] names the overloaded subscript operator.
// (int) means the function takes an int index.

// This differs from int operator[](int) const, so both overloads can coexist.