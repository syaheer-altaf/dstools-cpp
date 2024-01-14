/*
======================================================================
    Header file containing maximum heap interfaces.
    Author(s): Mohamed Syaheer Altaf
======================================================================
*/
#ifndef DSHEAP_HPP
#define DSHEAP_HPP

#include "DSArray.hpp"

namespace DSTools
{
// Heap inherits DArray class
template<typename T>
class Heap : public DArray<T>
{
protected:
    bool isMax;
    void heapify();
public:
    // Constructors
    Heap(bool);
    Heap();
    // Methods
    Heap& operator=(const Heap& obj)
    {
        // This copies the object and returns the pointer to be referenced
        if (this != &obj) {
            this->SIZE = obj.SIZE;
            this->CAPACITY = obj.CAPACITY;

            delete[] this->arr;
            this->arr = new T[this->CAPACITY];
            
            for (int i = 0; i < this->SIZE; i++ ) {
                this->arr[i] = obj.arr[i];
            }
        }
        return *this;
    }
    void push_back(T);
    T popMinMax();
    void setMinMax(bool);
    // Converts Heap class to DArray class and returns it 
    const DArray<T> getDArray();
};

}

#endif /*DSHEAP_HPP*/