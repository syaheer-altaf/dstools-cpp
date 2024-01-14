/*
======================================================================
    Header file containing heap sort interfaces.
    Author(s): Mohamed Syaheer Altaf
======================================================================
*/
#ifndef DSHEAPSORT_HPP
#define DSHEAPSORT_HPP

#include "DSHeap.hpp"
#include "DSArray.hpp"

namespace DSTools
{

template<typename T>
class HeapSort
{
private:
    Heap<T> arr;
    Heap<T> sortArr;
public:
    HeapSort(const Heap<T>&, bool);     // Heap sort leverages Heap class
    const Heap<T>& operator()()
    {
        return sortArr;
    }
};

}

#endif /*DSHEAPSORT_HPP*/