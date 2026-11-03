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

SafeArray operator+(const SafeArray &, int); // Accept a const reference to avoid copying SafeArray.
SafeArray operator+(int, const SafeArray &); // Accept a const reference to avoid copying SafeArray.

#endif

// These non-member overloads support SafeArray + int and int + SafeArray.
// The 100 + arr overload must be non-member because the left operand is an int.
// Binary arithmetic operators are often non-members so both operand orders can work.
// Unary operators are often members. For example, SafeArray &operator++()
// could increment every element and return *this by reference.

// A full implementation in .cpp could look like:
// SafeArray &SafeArray::operator++()
// {
//     for (int i = 0; i < size; i++)
//     {
//         dataptr[i] += 1;
//     }
//     return *this;
// }