/*
======================================================================
    Header file containing bubble sort interfaces.
    Author(s): Mohamed Syaheer Altaf
======================================================================
*/
#ifndef DSBUBBLESORT_HPP
#define DSBUBBLESORT_HPP

#include "DSArray.hpp"

namespace DSTools
{

template <typename T>
class BubbleSort
{
private:
    DArray<T> sortArr;
    bool isMax;
    void bubbleSort();
public:
    BubbleSort(const DArray<T>&, bool);
    const DArray<T>& operator()()
    {
        return sortArr;
    }
};

}
#endif /*DSBUBBLESORT_HPP*/