//
// Created by Arnav Chahal on 1/8/25.
// simple implemenation of a static array in cpp under the hood
// with a template for dynamic array typing
// and the big 4 constructors for clean up: copy, assignment, move, and destructor
//

#ifndef STATICARRAY_H
#define STATIC_ARRAY_H
#include <cstdint>
#include <cstdlib>
#include <stdexcept>
template<typename T> class StaticArray{
public:
    StaticArray():size(0), data(nullptr){

    }
    StaticArray(size_t const size, T initialValue):size(size),  data(new T[size]){
        std::fill(data,data+size,initialValue);
    }
    //destructor cleans up any extra data
    ~StaticArray() {
        delete[] data;
    }
    //copy constructor creates a deep copy of the static array object
    StaticArray(const StaticArray& other):size(other.size),data(new T[other.size]) {
        std::copy(other.data, other.data+other.size,data);

    }
    //move constructor quicker than copy assignment
    StaticArray(StaticArray&& other) noexcept:size(other.size),data(other.data) {
        other.data = nullptr;
        other.size = 0;
    }
    //copy assignment operator
    //pass by vlaue so we can swap the copies as garbage collection will save us
    StaticArray& operator=(StaticArray other){
        if (this != &other) {
            std::swap(size, other.size);
            std::swap(data, other.data);
        }
        return *this;
    }

    //move assignment operator
    StaticArray& operator=(StaticArray&& other) noexcept {
        if (this != &other) {
            std::swap(size,other.size);
            std::swap(data,other.data);
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
    // Access element with range checking
    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    size_t length() const{
        return size;
    }

private:
    size_t  size;
    T* data;

};
#endif //StaticArray_H
