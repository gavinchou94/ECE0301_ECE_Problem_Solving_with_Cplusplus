// This is a new SafeArray1.hpp
// This version:
// - Defines SafeArray with two private data members.
// - Declares two constructors, a destructor, and get_size().
// - One data member is a pointer.

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
};

#endif