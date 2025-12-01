// This is the final version of test_templates.cpp from last exercise
// rename it to test_interface.cpp

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "SafeArray.hpp"
#include "SearchableArray.hpp"
#include "UniqueArray.hpp"
#include "Date.hpp"

TEST_CASE("Test default construction of SafeArray", "[template]")
{
    SafeArray<int> arr;
    REQUIRE(arr.get_size() == 0);
}

TEST_CASE("Test SafeArray size construction and access using get/set", "[template]")
{
    int size = 5;
    SafeArray<int> arr(size);

    REQUIRE(arr.get_size() == size);
    for (int i = 0; i < size; i++)
    {
        arr.set(i, i);
        REQUIRE(arr.get(i) == i);
    }

    REQUIRE_THROWS_AS(arr.get(size), std::out_of_range);
    REQUIRE_THROWS_AS(arr.set(size, 0), std::out_of_range);
}

TEST_CASE("Test inheritance and search", "[template]")
{
    int size = 5;
    SearchableArray<double> arr(size);

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

TEST_CASE("Test inheritance and redefine/override", "[template]")
{
    int size = 5;
    UniqueArray<float> uarr(size);

    REQUIRE(uarr.get_size() == 5);

    for (int i = 0; i < size; i++)
    {
        // set uarr to be [1,2,3,4,5]
        uarr.set(i, i + 1.0);                               // overridden set functions
        REQUIRE(std::abs(uarr.get(i) - (i + 1.0)) <= 1e-9); // test success of overriding
    }

    // uarr[0]=5 would trigger exception since uarr[4]=5
    REQUIRE_THROWS_AS(uarr.set(0, 5), std::logic_error);
    REQUIRE_NOTHROW(uarr.set(0, -2)); // arr[0]=-2 is okay
    REQUIRE(uarr.get(0) == -2);

    SafeArray<char> *sa_ptr = new UniqueArray<char>(2);
    sa_ptr->set(0, 'x');
    REQUIRE_THROWS_AS(sa_ptr->set(1, 'x'), std::logic_error);
}

// define a function that takes a SafeArray<T> object
template <typename T>         // add template definition
void halve(SafeArray<T> &arr) // change argument to SafeArray<T>&
{
    for (int i = 0; i < arr.get_size(); i++)
    {
        arr.set(i, 0.5 * arr.get(i));
    }
}

// define a function that takes a SafeArray<T> ptr
template <typename T>          // add template definition
void halve(SafeArray<T> *sarr) // change argument to SafeArray<T>*
{
    for (int i = 0; i < sarr->get_size(); i++)
    {
        sarr->set(i, 0.5 * sarr->get(i));
    }
}

TEST_CASE("Test template function & binding", "[template]")
{
    int size = 5;
    SafeArray<int> arr(size);
    SafeArray<int> *arr_ptr = new SafeArray<int>(5);

    for (int i = 0; i < size; i++)
    {
        // set arr/arr_ptr to be [1,2,3,4,5]
        arr.set(i, i + 1);
        arr_ptr->set(i, i + 1);
    }

    halve(arr);
    halve(arr_ptr);

    for (int i = 0; i < size; i++)
    {
        // test arr/arrptr now to be [int(0.5*1),int(0.5*2),int(0.5*3),int(0.5*4),int(0.5*5)]
        REQUIRE(arr.get(i) == int(0.5 * (i + 1)));
        REQUIRE(arr_ptr->get(i) == int(0.5 * (i + 1)));
    }
}

template <typename T>                 // add template definition
T accumulate(const SafeArray<T> &arr) // include argument "const SafeArray<T>&"
{
    T sum = T(); // requires default constructor for type T
    for (int i = 0; i < arr.get_size(); i++)
    {
        sum = sum + arr.get(i); // requires operator+ for type T
    }
    return sum;
}

TEST_CASE("Test more functions of template", "[template]")
{
    int size = 5;
    SafeArray<double> arr(size);

    for (int i = 0; i < size; i++)
    {
        arr.set(i, i); // set arr to be [0.0,1.0,2.0,3.0,4.0]
    }

    double t_result = accumulate(arr);
    double t_expected = 10.0;
    REQUIRE(std::abs(t_expected - t_result) <= 1e-9);
}

TEST_CASE("Test template of ADT class", "[template]")
{
    int size = 3;
    SearchableArray<Date> sarr(size);

    sarr.set(0, Date(2020, JAN, 1));
    sarr.set(1, Date(2024, NOV, 19));
    sarr.set(2, Date(2024, NOV, 17));

    REQUIRE(sarr.search(Date(2020, JAN, 1))); // search is possible due to overloading operator== for Date class
    REQUIRE_FALSE(sarr.search(Date(2020, JAN, 2)));
}

struct Point // define an ADT struct Point
{
    int *x;
    int *y;

    Point() // default constructor
    {
        x = new int(0);
        y = new int(0);
    }

    Point(int a, int b) // parameterized constructor
    {
        x = new int(a);
        y = new int(b);
    }

    Point(const Point &p) // copy constructor
    {
        x = new int(*(p.x));
        y = new int(*(p.y));
    }
    Point &operator=(Point p) // copy assignment
    {
        std::swap(x, p.x);
        std::swap(y, p.y);
        return *this;
    }
    ~Point()
    {
        delete x;
        delete y;
    }
    bool operator==(const Point &p)
    {
        return (*x == *(p.x)) && (*y == *(p.y));
    }
};

Point operator+(const Point &p1, const Point &p2) // overload operator+ for Point struct
{
    return Point(*(p1.x) + *(p2.x), *(p1.y) + *(p2.y));
}

// Default constructor, assignment operator, operator== are defined for Point struct
// non-member operator+ is defined for Point struct
// So we can use SafeArray<Point>, SearchableArray<Point>, UniqueArray<Point> and functions like accumulate

TEST_CASE("Test template of ADT struct", "[template]")
{
    int size = 4;
    SafeArray<Point> arr(size); // test default constructor

    arr.set(0, Point(1, 2)); // test operator=
    arr.set(1, Point(3, 4));
    arr.set(2, Point(5, 6));
    arr.set(3, Point(7, 8));

    Point result = accumulate(arr);
    Point expected(16, 20); // (1+3+5+7, 2+4+6+8), test operator+

    REQUIRE(result == expected); // test operator==

    SearchableArray<Point> sarr(size);
    sarr.set(0, Point(1, 2));
    sarr.set(1, Point(3, 4));
    sarr.set(2, Point(5, 6));
    sarr.set(3, Point(7, 8));

    REQUIRE(sarr.search(Point(3, 4)));       // test operator==
    REQUIRE_FALSE(sarr.search(Point(0, 0))); // test operator==

    UniqueArray<Point> uarr(size);
    uarr.set(0, Point(1, 1));
    uarr.set(1, Point(2, 2));
    uarr.set(2, Point(3, 3));
    uarr.set(3, Point(4, 4));
    REQUIRE_THROWS_AS(uarr.set(1, Point(1, 1)), std::logic_error); // test operator==

    REQUIRE(Point(1, 3) == Point(2, 2) + Point(-1, 1)); // test non-member operator+
}