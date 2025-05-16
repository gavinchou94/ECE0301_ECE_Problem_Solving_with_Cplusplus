// This is the final version of test_interface.cpp
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Array.hpp"
#include "SafeArray.hpp"
#include "SearchableArray.hpp"
#include "UniqueArray.hpp"
#include "Date.hpp"

TEST_CASE("Test default construction of SafeArray", "[template]") {
    SafeArray<int> arr;
    REQUIRE(arr.get_size() == 0);
}

TEST_CASE("Test SafeArray size construction and access using get/set", "[template]") {
    int size = 5;
    SafeArray<int> arr(size);

    REQUIRE(arr.get_size() == size);
    for (int i=0; i<size; i++) {
        arr.set(i, i);
        REQUIRE(arr.get(i) == i);
    }

    REQUIRE_THROWS_AS(arr.get(size), std::out_of_range);
    REQUIRE_THROWS_AS(arr.set(size,0), std::out_of_range);
}

TEST_CASE("Test inheritance and search", "[template]") {
    int size = 5;
    SearchableArray<double> arr(size);

    REQUIRE(arr.get_size()==5);

    for (int i=0; i<size; i++){
        arr.set(i,i);                  // inherited from base class
        REQUIRE(arr.get(i)==i);        // inherited from base class
        REQUIRE(arr.search(i));        // derived class method
    }

    REQUIRE_FALSE(arr.search(-2));     // derived class method
    REQUIRE_THROWS_AS(arr.set(10, 10), std::out_of_range); // inherited from base class
}

TEST_CASE("Test inheritance and redefine/override", "[template]") {
    int size = 5;
    UniqueArray<float> uarr(size);

    REQUIRE(uarr.get_size()==5);

    for (int i=0; i<size; i++){
        // set uarr to be [1,2,3,4,5]
        uarr.set(i,i+1);                // overridden set functions
        REQUIRE(uarr.get(i)==i+1);      // test success of overriding
    }

    //uarr[0]=5 would trigger exception since uarr[4]=5
    REQUIRE_THROWS_AS(uarr.set(0, 5), std::logic_error);
    REQUIRE_NOTHROW(uarr.set(0, -2));   //arr[0]=-2 is okay
    REQUIRE(uarr.get(0)==-2);

    SafeArray<char> *sa_ptr = new UniqueArray<char>(2);
    sa_ptr->set(0, 'x');
    REQUIRE_THROWS_AS(sa_ptr->set(1, 'x'), std::logic_error);
    delete sa_ptr;
}

// define a function that takes a SafeArray<T> object
template <typename T>
void halve(SafeArray<T> & arr){
    for (int i=0; i<arr.get_size(); i++){
        arr.set(i,0.5*arr.get(i));
    }
}

// define a function that takes a SafeArray<T> ptr
template <typename T>
void halve(SafeArray<T>* sarr){
    for (int i=0; i<sarr->get_size(); i++){
        sarr->set(i,0.5*sarr->get(i));
    }
}

TEST_CASE("Test template function & binding", "[template]") {
    int size =5;
    SafeArray<int> arr(size);
    SafeArray<int>* arr_ptr = new SafeArray<int>(5);

    for (int i=0; i<size; i++){
        // set arr/arr_ptr to be [1,2,3,4,5]
        arr.set(i,i+1);
        arr_ptr->set(i,i+1);
    }

    halve(arr);
    halve(arr_ptr);

    for (int i=0; i<size; i++){
        // test arr/arrptr now to be [int(0.5*1),int(0.5*2),int(0.5*3),int(0.5*4),int(0.5*5)]
        REQUIRE(arr.get(i)==int(0.5*(i+1)));
        REQUIRE(arr_ptr->get(i)==int(0.5*(i+1)));
    }
}

template <typename T>
T accumulate(const SafeArray<T> & arr){
   T sum = T();
   for (int i=0; i<arr.get_size(); i++){
    sum = sum + arr.get(i);
   }
   return sum;
}

TEST_CASE("Test more functions of template", "[template]") {
    int size = 5;
    SafeArray<double> arr(size);

    for (int i=0; i<size; i++) {
        arr.set(i, i);
    }

    double t_result = accumulate(arr);
    double t_expected = 10;
    REQUIRE(std::abs(t_expected-t_result)<=1e-9);
}

TEST_CASE("Test template of ADT class", "[template]") {
    int size = 3;
    SearchableArray<Date> sarr(size);

    sarr.set(0, Date(2020, JAN, 1));
    sarr.set(1, Date(2024, NOV, 19));
    sarr.set(2, Date(2024, NOV, 17));

    REQUIRE(sarr.search(Date(2020, JAN, 1))); // search is possible due to overloading operator== for Date class
    REQUIRE_FALSE(sarr.search(Date(2020, JAN, 2)));
}

struct Entry {
    std::string name;
    int id;

    // define operator== for Entry, required for calling set() functions
    bool operator==(const Entry &e) const {
        return name == e.name && id == e.id;
    }
};

TEST_CASE("Test template of ADT struct", "[template]") {
    int size = 3;
    UniqueArray<Entry> uarr(size);

    uarr.set(0, {"sun", 10});
    uarr.set(1, {"moon", 299});
    uarr.set(2, {"mars", 399});

    REQUIRE_NOTHROW(uarr.set(0, {"earth", 100}));
    REQUIRE_THROWS_AS(uarr.set(0, {"moon", 299}), std::logic_error);
}

TEST_CASE("Test abstract class and interface inheritance", "[interface]") {
    bool sat1 = std::is_base_of<Array<int>, SafeArray<int>>::value;
    bool sat2 = std::is_base_of<SafeArray<int>, UniqueArray<int>>::value;
    bool sat3 = std::is_base_of<SafeArray<int>, SearchableArray<int>>::value;
    bool sat4 = std::is_base_of<Array<int>, UniqueArray<int>>::value;
    bool sat5 = std::is_base_of<Array<int>, SearchableArray<int>>::value;
    REQUIRE(sat1);
    REQUIRE(sat2);
    REQUIRE(sat3);
    REQUIRE(sat4);
    REQUIRE(sat5);

    bool sat6 = std::is_abstract<Array<int>>::value;
    bool sat7 = std::is_abstract<SafeArray<int>>::value;
    REQUIRE(sat6);
    REQUIRE_FALSE(sat7);
}

TEST_CASE("Test abstract class object and pointer", "[interface]") {

    // declaration of an object of abstract class is not allowed
    // Array<int> arr;

    // but declaration of a pointer of abstract class pointing to derived class object is allowed
    Array<int> *arr_ptr = new SafeArray<int>(5);
    REQUIRE(arr_ptr->get_size()==5);

    // declaration of a pointer of abstract class pointing to abstract class object is not allowed either
    // Array<int> *arr_ptr = new Array<int>;
}

class AnotherDerivedArray : public Array<int> {
    public:
        int get_size() const { return 0; }
        int get(int) const { return 0; }
};

TEST_CASE("Test derived class must implement all pure virtual functions", "[interface]") {

    //Comment below to check errors
    //AnotherDerivedArray arr;

    //Derived class must implement all pure virtual functions
    SafeArray<double> darr;
    REQUIRE(darr.get_size()==0);
}

class UncopyableArray {
    public:
        UncopyableArray() {}
        UncopyableArray(const UncopyableArray&) = delete;
        UncopyableArray& operator=(const UncopyableArray) = delete;
};

class DerivedUncopyableArray : public UncopyableArray {
    private:
        int size;
        int *dataptr;
    public:
        DerivedUncopyableArray(): size(0), dataptr(nullptr){}
        int get_size() {return size;}
};

TEST_CASE("Test derived class from uncopyable class", "[interface]") {
    DerivedUncopyableArray arr;
    REQUIRE(arr.get_size()==0);

    // uncomment below to check errors
    // object of uncopyable class (derived) cannot be copied
    // DerivedUncopyableArray arr2=arr;
    // DerivedUncopyableArray arr3(arr);

    // DerivedUncopyableArray arr4;
    // arr4=arr;

    // uncomment below to check errors
    // object of uncopyable class (base) cannot be copied
    // UncopyableArray barr;
    // UncopyableArray barr2=barr;
    // UncopyableArray barr3(barr);

    // UncopyableArray barr4;
    // barr4=barr;
}
