#ifndef FINAL_HPP
#define FINAL_HPP

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <vector>

// Regular class definition
class Final_v1
{
private:
    int num_course;
    int *course_code;

public:
    int some_func() const; // implemented in Final.cpp
};

// Template class definition
template <typename T>
class Final_v2
{
private:
    int num_course;
    T *course_info;

public:
    T another_func() const; // implemented in Final.tpp
};
#include "Final.tpp" // consider tpp as a part of this header file, extended header

// Abstract class definition
class Final_v3
{
public:
    virtual void func1() = 0; // no implementation at all
    virtual void func2() = 0; // no implementation at all
};

#endif