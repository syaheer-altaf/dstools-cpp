/*
======================================================================
    Header file containing merge sort interfaces.
    Author(s): Mohamed Syaheer Altaf
======================================================================
*/
#ifndef DSMERGESORT_HPP
#define DSMERGESORT_HPP

#include "DSArray.hpp"

namespace DSTools
{

template <typename T>
class MergeSort
{
private:
    DArray<T> sortArr;
    DArray<T> tempSort;
    bool isMax;

    DArray<T> sort_and_merge_subArr(DArray<T>&, DArray<T>&);
    const DArray<T>& mergeSortRecursion(DArray<T>&);
public:
    MergeSort(const DArray<T>&, bool);
    const DArray<T>& operator()()
    {
        return sortArr;
    }
        
};

}

#endif /*DSMERGESORT_HPP*/