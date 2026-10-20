#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>

struct Entry
{
  int id;
  std::string name;
  int units, pins, transistors;
  double max_delay, power_per_unit, bulk_price;
};

// Database class declaration.
class Database
{
private:
  int num_entries;
  std::vector<Entry> data;

public:
  // Default constructor.
  Database();

  // Other public functions go here.

  void sort_by_name();
  int search_criteria(double upper[3]) const;
};

#endif