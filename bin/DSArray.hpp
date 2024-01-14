/*
======================================================================
    Header file containing dynamic array interfaces.
    Author(s): Mohamed Syaheer Altaf
======================================================================
*/
#ifndef DSARRAY_HPP
#define DSARRAY_HPP

#include <stdexcept>

namespace DSTools
{

template <typename T>
class DArray
{
protected:
    T* arr = nullptr;
    int SIZE;           // The current size of the array
    int CAPACITY;       // The container of the array that grows or shrink dynamically.
    // Private methods
    void doubleCapacity();
    void halfCapacity();
public:
    DArray();
    DArray(const DArray<T>&);
    ~DArray();
    int size();
    // Declare and define overload functions (define the operators)
    T& operator[](int index)
    {
        // This returns the reference to a specified index of an array
        if (index >= SIZE || index < 0) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }
    DArray& operator=(const DArray& obj)
    {
        // This copies the object and returns the pointer to be referenced
        if (this != &obj) {
            SIZE = obj.SIZE;                // copy new size
            CAPACITY = obj.CAPACITY;       //  copy new capacity

            delete[] this->arr;           //   delete old array (necessary!)
            arr = new T[CAPACITY];      //    declare new array with correct capacity.

            for(int i = 0; i < SIZE; i++ ) {
                arr[i] = obj.arr[i];
            }
        }
        return *this;
    }
    // Declare methods
    void push_back(T);
    T pop_back();   
};

}

#endif /*DSARRAY_HPP*/