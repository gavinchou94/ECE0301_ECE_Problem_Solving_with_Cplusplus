// This file is expected to contain the declaration of the Array class (a re-based class, pure virtual)
// SafeArray class is now derived from Array class

#ifndef _ARRAY_HPP
#define _ARRAY_HPP

template <typename T>
class Array {
    
    public:  // this can be omitted, since default access specifier is public
        virtual int get_size() const = 0;
        virtual T get(int) const = 0;
        virtual void set(int, T) = 0;
};

#endif