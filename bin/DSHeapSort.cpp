/*////////////////////////////////////////////////////////
    HEAP SORT ALGORITHM
    Author(s): Mohamed Syaheer Altaf
    -----------------------------------------------------
    SOME IMPORTANT NOTE FOR HEAP SORT:
    -> Heap sort inherits the Heap class.
    -> The algorithm described in popMinMax():
        a) Return the element in the first index of the heapified array.
        b) Copy the element in the last index to the first index.
        c) Pop the last index.
        d) heapify() to retain the structure.

*/////////////////////////////////////////////////////////

#include "DSHeapSort.hpp"
using namespace DSTools;

/*HEAP SORT IMPLEMENTATION*/
template<typename T>
HeapSort<T>::HeapSort(const Heap<T>& arr, bool isMax)
{
    this->arr = arr;                     // To avoid from modifying the original Heap object.
    this->arr.setMinMax(isMax);
    sortArr.setMinMax(isMax);
    const int size = this->arr.size();         // Because the size reduces after each pop.

    // Implement Heap Sort Algorithm
    for (int i = 0; i < size; i++) {
        T temp = this->arr.popMinMax(); // Pop max or min and heapify in the function
        sortArr.push_back(temp);
    }
}

// Explicit instantiations
template class HeapSort<int>;
template class HeapSort<float>;
template class HeapSort<double>;
template class HeapSort<char>;
// Add more instantiations for other datatypes as needed