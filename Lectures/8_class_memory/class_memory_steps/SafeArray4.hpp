// This is SafeArray4.hpp
// Changes from SafeArray3.hpp:
// - Adds copy assignment.
// - Explains the copy-swap idiom.

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

  // Copy-assignment operator.
  SafeArray &operator=(SafeArray s);
  // Copy assignment updates the left-hand object and returns it by reference,
  // allowing chained assignments such as a = b = c.
  // The parameter is passed by value,
  // so the copy constructor creates a copy of the right-hand object.

  int get_size() const;
  int operator[](int) const; // Read an element using [].
  int &operator[](int);      // Return an element by reference so it can be modified using [].
};

#endif

// Copy-swap idiom:
// The copy-assignment operator above uses copy-swap:
// 1. Pass the right-hand object by value to make a copy.
// 2. Swap this object's members with the copy's members.
// 3. Return *this.

// This handles self-assignment
// and frees the old array when the copy goes out of scope.

// Copy-swap always copies the right-hand object,
// which can be expensive for large objects.