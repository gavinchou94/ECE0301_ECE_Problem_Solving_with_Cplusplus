#define CATCH_CONFIG_MAIN

#include <iostream>

#include "SafeArray.hpp"
#include "SearchableArray.hpp"
#include "UniqueArray.hpp"
#include "catch.hpp"

TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]")
{
  int size = 5;
  SafeArray arr(size);

  REQUIRE(arr.get_size() == size);
  for (int i = 0; i < size; i++)
  {
    arr.set(i, i);
    REQUIRE(arr.get(i) == i);
  }

  REQUIRE_THROWS_AS(arr.get(size), std::out_of_range);
  REQUIRE_THROWS_AS(arr.set(size, 0), std::out_of_range);
}

TEST_CASE("Test inheritance and search", "[inh]")
{
  int size = 5;
  SearchableArray arr(size); // use constructor inherited from SafeArray

  REQUIRE(arr.get_size() == 5);

  for (int i = 0; i < size; i++)
  {
    arr.set(i, i);            // inherited from base class
    REQUIRE(arr.get(i) == i); // inherited from base class
    REQUIRE(arr.search(i));   // derived class method
  }

  REQUIRE_FALSE(arr.search(-2));                         // derived class method
  REQUIRE_THROWS_AS(arr.set(10, 10), std::out_of_range); // inherited from base class
}

TEST_CASE("Test inheritance access permission", "[inh]")
{
  int size = 5;
  SearchableArray arr(size);
  REQUIRE(arr.search(0)); // derived class method, built on get() since dataptr is private again
}

TEST_CASE("Test inheritance and redefine/override", "[inh]")
{
  int size = 5;
  UniqueArray uarr(size);

  REQUIRE(uarr.get_size() == 5);

  for (int i = 0; i < size; i++)
  {
    // set uarr to be {1,2,3,4,5}
    uarr.set(i, i + 1);            // overridden set function
    REQUIRE(uarr.get(i) == i + 1); // test success of overriding
  }

  // uarr.set(0, 5) would trigger uniqueness exception since index 4 already holds 5
  REQUIRE_THROWS_AS(uarr.set(0, 5), std::logic_error);
  REQUIRE_NOTHROW(uarr.set(0, -2)); // -2 is not in the array yet, so this is okay
  REQUIRE(uarr.get(0) == -2);
}

TEST_CASE("Test polymorphism", "[inh]")
{
  // You can use a base class pointer to point to a derived class object
  SafeArray *sa_ptr = new UniqueArray(2);
  sa_ptr->set(0, 100);
  REQUIRE_THROWS_AS(sa_ptr->set(1, 100), std::logic_error);
  delete sa_ptr;
}

// define a function that takes a SafeArray object (by reference)
// and apply half to the arr object memberwise
void halve1(SafeArray &arr)
{
  for (int i = 0; i < arr.get_size(); i++)
  {
    arr.set(i, arr.get(i) / 2);
  }
}

// define a function that takes a SafeArray ptr
// and apply half to the arr object memberwise
void halve2(SafeArray *sarr)
{
  for (int i = 0; i < sarr->get_size(); i++)
  { // note that (*x).y is just x->y
    sarr->set(i, sarr->get(i) / 2);
  }
}

// define a function that takes a SafeArray object (by value)
// and apply half to the arr object memberwise
void halve3(SafeArray arr)
{
  for (int i = 0; i < arr.get_size(); i++)
  {
    arr.set(i, arr.get(i) / 2);
  }
}

TEST_CASE("Test non-member functions", "[inh]")
{
  int size = 5;
  SafeArray arr1(size);
  SafeArray *arr2_ptr = new SafeArray(size);
  SafeArray arr3(size);

  for (int i = 0; i < size; i++)
  {
    // set arr1/arr2_ptr/arr3 to be {1,2,3,4,5}
    arr1.set(i, i + 1);
    arr2_ptr->set(i, i + 1);
    arr3.set(i, i + 1);
  }

  halve1(arr1);
  halve2(arr2_ptr);
  halve3(arr3);

  for (int i = 0; i < size; i++)
  {
    // test arr1/arr2_ptr/arr3
    REQUIRE(arr1.get(i) == (i + 1) / 2);
    REQUIRE(arr2_ptr->get(i) == (i + 1) / 2);
    REQUIRE(arr3.get(i) == i + 1);
    // arr3 remains unchanged since it is passed by value
  }
  delete arr2_ptr;
}

TEST_CASE("Test polymorphism with functions passing", "[inh]")
{
  int size = 5;
  UniqueArray uarr1(size);
  SafeArray *uarr2_ptr = new UniqueArray(size);
  UniqueArray uarr3(size);

  for (int i = 0; i < size; i++)
  {
    // set uarr1/uarr2_ptr/uarr3 to be {1,2,3,4,5}
    uarr1.set(i, i + 1);
    uarr2_ptr->set(i, i + 1);
    uarr3.set(i, i + 1);
  }

  REQUIRE_THROWS_AS(halve1(uarr1), std::logic_error);
  REQUIRE_THROWS_AS(halve2(uarr2_ptr), std::logic_error);
  REQUIRE_NOTHROW(halve3(uarr3));
  delete uarr2_ptr;
}

// delete "virtual" in SafeArray.hpp to see Case 3 change
TEST_CASE("Summarized Test on Binding", "[binding]")
{
  int size = 5;
  SafeArray sarr(size);                                 // a SafeArray object
  UniqueArray uarr(size);                               // a UniqueArray object
  SafeArray *sarr_ptr = new SafeArray(size);            // SafeArray pointer to a SafeArray object
  UniqueArray *uarr_ptr = new UniqueArray(size);        // UniqueArray pointer to a UniqueArray object
  SafeArray *sarr_ptr_to_uaobj = new UniqueArray(size); // SafeArray pointer to a UniqueArray object
  SafeArray &sarr_ref_to_uaobj = uarr;                  // SafeArray reference to a UniqueArray object
  // UniqueArray *uarr_ptr_to_saobj = new SafeArray(size); // does not compile

  for (int i = 0; i < size; i++)
  {
    // set every array to be {1,2,3,4,5}
    sarr.set(i, i + 1);
    uarr.set(i, i + 1);
    sarr_ptr->set(i, i + 1);
    uarr_ptr->set(i, i + 1);
    sarr_ptr_to_uaobj->set(i, i + 1);
  }

  // Does halving {1,2,3,4,5} into {0,1,1,2,2} make set() throw?

  // Case 1: a SafeArray object (or a sliced copy), so SafeArray::set runs: never throws
  REQUIRE_NOTHROW(halve1(sarr));
  REQUIRE_NOTHROW(halve2(sarr_ptr));
  REQUIRE_NOTHROW(sarr.set(0, 4));
  REQUIRE_NOTHROW(sarr_ptr->set(0, 4));
  REQUIRE_NOTHROW(halve3(uarr)); // pass by value: the copy is a plain SafeArray

  // Case 2: a UniqueArray called through its own type, so UniqueArray::set runs: always throws
  REQUIRE_THROWS_AS(uarr.set(0, 4), std::logic_error);
  REQUIRE_THROWS_AS(uarr_ptr->set(0, 4), std::logic_error);

  // Case 3: a UniqueArray seen through a SafeArray & or *: depends on "virtual"
  REQUIRE_THROWS_AS(halve1(uarr), std::logic_error);
  REQUIRE_THROWS_AS(sarr_ref_to_uaobj.set(0, 4), std::logic_error);
  REQUIRE_THROWS_AS(halve2(uarr_ptr), std::logic_error);
  REQUIRE_THROWS_AS(halve2(sarr_ptr_to_uaobj), std::logic_error);
  REQUIRE_THROWS_AS(sarr_ptr_to_uaobj->set(0, 4), std::logic_error);
  // without "virtual", the five lines above fail; these pass instead:
  // REQUIRE_NOTHROW(halve1(uarr));
  // REQUIRE_NOTHROW(sarr_ref_to_uaobj.set(0, 4));
  // REQUIRE_NOTHROW(halve2(uarr_ptr));
  // REQUIRE_NOTHROW(halve2(sarr_ptr_to_uaobj));
  // REQUIRE_NOTHROW(sarr_ptr_to_uaobj->set(0, 4));

  delete sarr_ptr;
  delete uarr_ptr;
  delete sarr_ptr_to_uaobj;
}

// Refer to https://stackoverflow.com/questions/26743991/redefining-vs-overriding-in-c
TEST_CASE("Demo 1: Derived Class Function Redefinition", "[demo]")
{
  std::cout << "Demo 1: (without virtual)" << std::endl;
  class Base
  {
  public:
    virtual ~Base() // virtual destructor, so deleting a Derived through a Base * is safe
    {
    }
    // notice that the greetings function is NOT virtual
    void greetings() const
    {
      std::cout << "Hi, I'm from Base class" << std::endl;
    }
  };

  class Derived : public Base
  {
  public:
    // redefinition of the function
    void greetings() const
    {
      std::cout << "Hi, I'm from Derived class" << std::endl;
    }
  };

  std::cout << "First call:" << std::endl;
  std::cout << "Using Base object" << std::endl;
  Base b;
  b.greetings(); // Output: Hi, I'm from Base class
  // static binding

  std::cout << "Second call:" << std::endl;
  std::cout << "Using Derived object" << std::endl;
  Derived d;
  d.greetings(); // Output: Hi, I'm from Derived class
  // static binding

  std::cout << "Third call:" << std::endl;
  std::cout << "Using Base pointer to Derived object" << std::endl;
  Base *b_ptr = new Derived();
  b_ptr->greetings(); // Output: Hi, I'm from Base class <== PROBLEM
                      // Expected: Hi, I'm from Derived class
                      // static binding
                      // The compiler only knows that b_ptr is a pointer to Base object, so it binds the
                      // method Base::greetings at compile time.
  delete b_ptr;
  std::cout << std::endl;
}

TEST_CASE("Demo 2: Derived Class Function Overriding", "[demo]")
{
  std::cout << "Demo 2: (with virtual)" << std::endl;
  class Base
  {
  public:
    virtual ~Base() // virtual destructor, so deleting a Derived through a Base * is safe
    {
    }
    // notice that the greetings function is virtual
    virtual void greetings() const
    {
      std::cout << "Hi, I'm from Base class" << std::endl;
    }
  };

  class Derived : public Base
  {
  public:
    // overriding the function
    void greetings() const
    {
      std::cout << "Hi, I'm from Derived class" << std::endl;
    }
  };

  std::cout << "First call:" << std::endl;
  std::cout << "Using Base object" << std::endl;
  Base b;
  b.greetings(); // Output: Hi, I'm from Base class
  // static binding

  std::cout << "Second call:" << std::endl;
  std::cout << "Using Derived object" << std::endl;
  Derived d;
  d.greetings(); // Output: Hi, I'm from Derived class
  // static binding

  std::cout << "Third call:" << std::endl;
  std::cout << "Using Base pointer to Derived object" << std::endl;
  Base *b_ptr = new Derived();
  b_ptr->greetings(); // Output: Hi, I'm from Derived class (Expected)
                      // dynamic binding
                      // The idea of using virtual functions tells the compiler NOT to bind the
                      // method at compile-time, but instead defer to run-time.
  delete b_ptr;
  std::cout << std::endl;
}

class Base
{
public:
  virtual ~Base() // virtual destructor, so deleting a Derived through a Base * is safe
  {
  }
  // notice that the greetings function is virtual
  virtual void greetings() const
  {
    std::cout << "Hi, I'm from Base class" << std::endl;
  }
};

class Derived : public Base
{
public:
  // overriding the function
  void greetings() const
  {
    std::cout << "Hi, I'm from Derived class" << std::endl;
  }
};

void another_greeting(Base *obj)
{
  obj->greetings();
}

TEST_CASE("Test function pass", "[demo]")
{
  std::cout << "Test function pass: (with virtual)" << std::endl;
  std::cout << "Using Base pointer to Derived object, passed to a function" << std::endl;
  Base *b = new Derived();
  another_greeting(b);
  delete b;
} // Not a good idea to declare classes in test cases but for demonstration purposes only

TEST_CASE("Test virtual destructor", "[inh]")
{
  // a derived class with heap memory of its own: only ~LoggedArray frees it
  class LoggedArray : public SafeArray
  {
  public:
    LoggedArray(int n) : SafeArray(n), log_buffer(new int[n])
    {
    }
    // never copied in this test, so no copy constructor or assignment is written

    ~LoggedArray()
    {
      std::cout << "LoggedArray destructor: frees its own heap memory" << std::endl;
      delete[] log_buffer;
    }

  private:
    int *log_buffer; // LoggedArray's own heap memory
  };

  std::cout << std::endl << "Delete a LoggedArray through a SafeArray *:" << std::endl;
  SafeArray *sa_ptr = new LoggedArray(2);
  delete sa_ptr; // ~SafeArray is virtual, so ~LoggedArray runs first and frees log_buffer
  // remove "virtual" from ~SafeArray in SafeArray.hpp: the line disappears, log_buffer leaks, and g++ -Wall warns
}