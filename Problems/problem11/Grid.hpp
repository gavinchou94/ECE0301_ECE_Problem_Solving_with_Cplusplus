#ifndef _GRID_HPP
#define _GRID_HPP

struct Location {
    int row;
    int col;
};

class Grid {
    private:
        int size;
        int** data;

    public:
        static const int DEFAULT_SIZE;
        Grid();
        Grid(int start_size);
        Grid(const Grid& gcopy) = delete; // not copyable
        Grid operator=(const Grid& g) = delete; // not copyable
        ~Grid();
        int get_size() const;
        int* get_cell(Location loc) const;
        void set_cell(Location loc, int* val);
        bool move(Location from, Location to);
        void clear();
        void resize(int new_size);
        
};

#endif