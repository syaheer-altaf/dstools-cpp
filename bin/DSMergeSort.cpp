/*////////////////////////////////////////////////////////
    MERGE SORT ALGORITHM
    Author(s): Mohamed Syaheer Altaf
    -----------------------------------------------------
    SOME IMPORTANT NOTE FOR MERGE SORT:
    1) Divide the unsorted list into n sublists, each containing one element 
       (a list of one element is considered sorted).
    2) Repeatedly merge sublists to produce new sorted sublists until there is 
       only one sublist remaining. This will be the sorted list.

*/////////////////////////////////////////////////////////

#include "DSMergeSort.hpp"
using namespace DSTools;

/*MERGE SORT IMPLEMENTATION*/
// Constructor
template<typename T>   
MergeSort<T>::MergeSort(const DArray<T>& arr, bool isMax)
{
    sortArr = arr;                     // To avoid modifying original DArray
    this->isMax = isMax;
    sortArr = mergeSortRecursion(sortArr);
}
// Methods
template<typename T>
DArray<T>
MergeSort<T>::
sort_and_merge_subArr(DArray<T>& leftArr, DArray<T>& rightArr)
{
    DArray<T> merge;
    int i = 0, j = 0;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (isMax ? leftArr[i] >= rightArr[j] : leftArr[i] <= rightArr[j]) {
            merge.push_back(leftArr[i]);
            i++;
        }
        else {
            merge.push_back(rightArr[j]);
            j++;
        }
    }
    // If there are any elements left in leftArr
    while (i < leftArr.size()) {
        merge.push_back(leftArr[i]);
        i++;
    }
    // If there are any elements left in rightArr
    while (j < rightArr.size()) {
        merge.push_back(rightArr[j]);
        j++;
    }
    
    return merge;
}
template<typename T>
const DArray<T>& MergeSort<T>::mergeSortRecursion(DArray<T>& arr)
{
    if (arr.size() == 1) return arr;

    int mid = arr.size() / 2;
    DArray<T> leftArray, rightArray;

    // Divide array into two sub-arrays
    for (int i = 0; i < mid; i++) {
        leftArray.push_back(arr[i]);
    }
    for (int i = mid; i < arr.size(); i++) {
        rightArray.push_back(arr[i]);
    }
    // Recursively divide until array size = 1 for both leftArray and rightArray
    leftArray = mergeSortRecursion(leftArray);
    rightArray = mergeSortRecursion(rightArray);
    tempSort = sort_and_merge_subArr(leftArray, rightArray); // sort and merge sub-arrays

    return tempSort; // return monotone of sub-arrays and finally the sorted array
}

// Explicit instantiations
template class MergeSort<int>;
template class MergeSort<float>;
template class MergeSort<double>;
template class MergeSort<char>;
// Add more instantiations for other datatypes as needed