// This is SafeArray2.hpp
// No changes from SafeArray1.hpp.

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
  ~SafeArray(); // has to include this due to dataptr

  // this is copy constructor
  SafeArray(const SafeArray &);

  // this is copy assignment
  SafeArray &operator=(SafeArray);

  int get_size() const;
  int get(int) const; // change [] to get() for SafeArray object to access
  void set(int, int); // change [] to set( , ) for SafeArray object to update
};

SafeArray operator+(const SafeArray &, int); // pass by const reference
SafeArray operator+(int, const SafeArray &); // pass by const reference

#endif