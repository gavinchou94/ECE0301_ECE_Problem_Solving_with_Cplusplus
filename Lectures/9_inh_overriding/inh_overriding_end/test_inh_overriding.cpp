// This is final version of test_inh_overriding.cpp
// Clear some comments of test_inh_overriding4.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray.hpp"
#include "SearchableArray.hpp"
#include "UniqueArray.hpp"

TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    REQUIRE(arr.get_size() == size);
    for (int i=0; i<size; i++) {
        arr.set(i, i);
        REQUIRE(arr.get(i) == i);
    }

    REQUIRE_THROWS_AS(arr.get(size), std::out_of_range);
    REQUIRE_THROWS_AS(arr.set(size,0), std::out_of_range);
}

TEST_CASE("Test inheritance and search", "[inh]") {
    int size = 5;
    SearchableArray arr(size);

    REQUIRE(arr.get_size()==5);

    for (int i=0; i<size; i++){
        arr.set(i,i);                  // inherited from base class 
        REQUIRE(arr.get(i)==i);        // inherited from base class
        REQUIRE(arr.search(i));        // derived class method
    }

    REQUIRE_FALSE(arr.search(-2));     // derived class method
    REQUIRE_THROWS_AS(arr.set(10, 10), std::out_of_range); // inherited from base class
}

TEST_CASE("Test inheritance access permission", "[inh]") {
    int size = 5;
    SearchableArray arr(size);
    REQUIRE(arr.search(0));     // derived class method built on "protected" var
}

TEST_CASE("Test inheritance and redefine/override", "[inh]") {
    int size = 5;
    UniqueArray uarr(size);

    REQUIRE(uarr.get_size()==5);

    for (int i=0; i<size; i++){
        // set uarr to be [1,2,3,4,5]
        uarr.set(i,i+1);                // overridden set functions
        REQUIRE(uarr.get(i)==i+1);      // test success of overriding
    }

    //arr[0]=5 would trigger exception since arr[4]=5
    REQUIRE_THROWS_AS(uarr.set(0, 5), std::logic_error);
    REQUIRE_NOTHROW(uarr.set(0, -2));   //arr[0]=-2 is okay
    REQUIRE(uarr.get(0)==-2);

    // these following 3 lines demonstrates dynamic binding
    // delete "virtual" at Line 27 of SafeArray3.hpp and try it again
    SafeArray *sa_ptr = new UniqueArray(2);
    sa_ptr->set(0, 100);
    //REQUIRE_THROWS_AS(sa_ptr->set(1, 100), std::logic_error);
}

// define a function that takes a SafeArray object (as a reference)
// and apply half to the arr object memberwise 
void halve(SafeArray & arr){
    int val;
    for (int i=0; i<arr.get_size(); i++){
        val = 0.5*arr.get(i);
        arr.set(i,val);
    }
}

// define a function that takes a SafeArray ptr
// and apply half to the arr object memberwise 
void halve(SafeArray* sarr){
    int val;
    for (int i=0; i<sarr->get_size(); i++){   //note that (*x).y is just x->y
        val = 0.5*sarr->get(i);
        sarr->set(i,val);
    }
}

TEST_CASE("Test non-member functions", "[inh]") {
    int size =5;
    SafeArray arr(size);
    SafeArray* arr_ptr = new SafeArray(5);

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

// delete "virtual" at Line 27 of SafeArray3.hpp and try it again
// test at Line 136, 141, 146 would all fail
TEST_CASE("Test binding on passing base class to functions", "[binding]") {
    int size =5;
    SafeArray sarr(size);
    UniqueArray uarr(size);

    SafeArray* sarr_ptr = new SafeArray(size);
    UniqueArray* uarr_ptr = new UniqueArray(size);
    SafeArray* sarr_ptr_to_uaobj = new UniqueArray(size);

    for (int i=0; i<size; i++){
        sarr.set(i,i+1); // all arr set to be 1,2,3,4,5
        uarr.set(i,i+1); 
        sarr_ptr->set(i,i+1);
        uarr_ptr->set(i,i+1);
        sarr_ptr_to_uaobj->set(i,i+1);
    }
    // expected half arr 0,1,1,2,2 and would trigger UniqueArray::set() to throw
    REQUIRE_NOTHROW(halve(sarr));
    REQUIRE_NOTHROW(halve(sarr_ptr));

    REQUIRE_THROWS_AS(halve(uarr), std::logic_error);
    
    //uarr_ptr points to a UniqueArray object
    //when it's passed to halve(*) function, function dynamically binds UniqueArray::set()
    //in its runtime, this is dynamic binding, compared to static binding at compile time
    REQUIRE_THROWS_AS(halve(uarr_ptr), std::logic_error);
    
    //sarr_ptr_to_uaobj points to a UniqueArray object, although it's SafeArray ptr
    //when it's passed to halve(*) function, function dynamically binds UniqueArray::set()
    //in its runtime, this is dynamic binding, compared to static binding at compile time
    REQUIRE_THROWS_AS(halve(sarr_ptr_to_uaobj), std::logic_error);

    //UniqueArray* uarr_ptr_to_saobj = new SafeArray(size); 
    //a value of type "SafeArray *" cannot be used to initialize an entity of type "UniqueArray *"
}

// Refer to https://stackoverflow.com/questions/26743991/redefining-vs-overriding-in-c

class Base {
    public:
        // notice that the function is virtual
        virtual void greetings() const {
            std::cout << "Hi, I'm from Base class" << std::endl;
        }
};

class Derived : public Base {
    public:
        // overriding of the function
        void greetings() const {
            std::cout << "Hi, I'm from Derived class" << std::endl;
        }
};

void another_greeting(Base *obj){
        obj->greetings();
}

TEST_CASE("Test function pass", "[demo]"){
    Base *b = new Derived();
    another_greeting(b);
}

TEST_CASE("Demo 1: Derived Class Function Redefinition", "[demo]"){
    
    std::cout << "Demo 1:" << std::endl;
    class Base {
        public:
            // notice that the function is NOT virtual
            void greetings() const {
                std::cout << "Hi, I'm from Base class" << std::endl;
            }
    };

    class Derived : public Base {
        public:
            // redefinition of the function
            void greetings() const {
                std::cout << "Hi, I'm from Derived class" << std::endl;
            }
    };

    Base b;
    b.greetings(); // Output: Hi, I'm from Base class
    // static binding

    Derived d;
    d.greetings();  // Output: Hi, I'm from Derived class
    // static binding

    Base *b_ptr = new Derived();
    b_ptr->greetings(); // Output: Hi, I'm from Base class <== PROBLEM
                        // Expected: Hi, I'm from Derived class
    // static binding
    // Compiler all knows that b_ptr is a pointer to Base object, so it binds the
    // method Base::greetings at compile time.
}

TEST_CASE("Demo 2: Derived Class Function Overriding", "[demo]"){
    
    std::cout << "Demo 2:" << std::endl;
    class Base {
        public:
            // notice that the function is virtual
            virtual void greetings() const {
                std::cout << "Hi, I'm from Base class" << std::endl;
            }
    };

    class Derived : public Base {
        public:
            // overriding the function
            void greetings() const {
                std::cout << "Hi, I'm from Derived class" << std::endl;
            }
    };

    Base b;
    b.greetings(); // Output: Hi, I'm from Base class
    // static binding

    Derived d;
    d.greetings();  // Output: Hi, I'm from Derived class
    // static binding

    Base *b_ptr = new Derived();
    b_ptr->greetings();   // Output: Hi, I'm from Derived class (Expected)
    // dynamic binding
    // The idea of using virtual functions tells the compiler NOT to bind the 
    // method at compile-time, but instead defer to run-time.
}