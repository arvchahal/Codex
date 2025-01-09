//
// Created by Arnav Chahal on 1/8/25.
// simple implemenation of a static array in cpp under the hood
// with a template for dynamic array typing
// and the big 4 constructors for clean up: copy, assignment, move, and destructor
//

#ifndef ARRAY_H
#define ARRAY_H

template<typename T> class Array{
public:
    Array():size(0), data(nullptr){

    }
    Array(size_t const size, T intialValue):SIZE(size),  data(new T[SIZE]){
        for(size_t i =0; i<SIZE;++i) {
            data[i]=intialValue;
        }
    }
    ~Array() {
        delete[] data;
    }
    Array(const Array& other);
    Array& operator=(Array&& other) noexcept;
    Array& operator=(Array other);

    int length() const{
        return SIZE;
    }

private:
    T* data;
    const size_t SIZE;
#include "../src/Array.cpp"
};
#endif //ARRAY_H
