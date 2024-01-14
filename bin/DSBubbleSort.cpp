/*////////////////////////////////////////////////////////
    BUBBLE SORT ALGORITHM
    Author(s): Mohamed Syaheer Altaf
    -----------------------------------------------------
    SOME IMPORTANT NOTE FOR BUBBLE SORT:
    1) A simple sorting implementation that swaps adjacent cells of an array if needed,
       depending on min and max.
    2) After every i-th step, (n-i)-th cell will hold the largest or smallest value
       relative to the remaining unsorted cells. Note that n = size of array, and
       i starts from 0. 

*/////////////////////////////////////////////////////////

#include "DSBubbleSort.hpp"
using namespace DSTools;

/*BUBBLE SORT IMPLEMENTATION*/
// Constructor
template<typename T>
BubbleSort<T>::BubbleSort(const DArray<T>& arr, bool isMax)
{
    sortArr = arr;          // To avoid modifying original DArray
    this->isMax = isMax;
    bubbleSort();
}
// Methods
template<typename T>
void BubbleSort<T>::bubbleSort()
{
    for (int i = 0; i < sortArr.size() - 1; i++) {
        for (int j = 0; j < sortArr.size() - 1 - i; j++) {
            if (isMax ? sortArr[j + 1] > sortArr[j] : sortArr[j + 1] < sortArr[j]) {
                T temp = sortArr[j];
                sortArr[j] = sortArr[j + 1];
                sortArr[j + 1] = temp;
            }
        }
    }
}

// Explicit instantiations
template class BubbleSort<int>;
template class BubbleSort<float>;
template class BubbleSort<double>;
template class BubbleSort<char>;
// Add more instantiations for other datatypes as needed