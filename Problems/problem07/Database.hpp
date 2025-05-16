#ifndef _DATABASE_HPP
#define _DATABASE_HPP

#include <string>
#include <vector>

struct Entry
{
    int id;
    std::string name;
    int units, pins, transistors;
    double max_delay, power_per_unit, bulk_price;
};

// Database class declaration below
class Database
{
private:
    int num_entries;
    std::vector<Entry> data;

public:
    // default constructor
    Database();

    // other public functions go here

    void sort_by_name();
    int search_criteria(double upper[3]) const;
};

#endif
