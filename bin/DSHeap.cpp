/*////////////////////////////////////////////////////////
    MIN/MAX HEAP ALGORITHM
    Author(s): Mohamed Syaheer Altaf
    -----------------------------------------------------
    SOME IMPORTANT NOTE FOR MIN/MAX HEAP:
    -> Root is at index 0 in array.
    -> Left child of i-th node is at (2*i + 1)th index.
    -> Right child of i-th node is at (2*i + 2)th index.
    -> Parent of i-th node is at (i-1)/2 index.

*/////////////////////////////////////////////////////////

#include "DSHeap.hpp"
using namespace DSTools;

/* MIN/MAX HEAP IMPLEMENTATION */
// Constructors
template <typename T>
Heap<T>::Heap(bool isMax) : DArray<T>()
{
    this->isMax = isMax;
}
template <typename T>
Heap<T>::Heap() : DArray<T>()
{
    this->isMax = true;
}
// Methods
template <typename T>
void Heap<T>::push_back(T value)
{
    DArray<T>::push_back(value);
    heapify();                          // Retains heap structure
}
template<typename T>
T Heap<T>::popMinMax()
{ 
    T temp = this->arr[0];                  // The max or min element after heapify
    this->arr[0] = this->arr[this->SIZE - 1];
    DArray<T>::pop_back();
    heapify();                         // Make sure the max heap structure retains
                                       // especially when implementing heap sort after each pop.
    return temp;
}
template<typename T>
void Heap<T>::heapify()
{
    // Identify index of last non-leaf node
    int startIndex = (this->SIZE/2) - 1;

    /* Perform reverse level order traversal from last non-leaf node 
        and heapify each node */
    for (int i = startIndex; i >= 0; i--) {
        // Check for conditions recursively (do until max == i)
        while (true) {
            int max = i;                // Init root as the max or min (assumption)
            int leftChild = 2*i + 1;    // Identify left-child index
            int rightChild = 2*i +2;    // Identify right-child index
            
            // The logic

            // If left-child is larger than root (opposite for min)
            if (isMax ? leftChild < this->SIZE && this->arr[leftChild] > this->arr[max] :
                        leftChild < this->SIZE && this->arr[leftChild] < this->arr[max]) {
                max = leftChild;
            }

            // If right-child is larger than root and/or left-child (opposite for min)
            if (isMax ? rightChild < this->SIZE && this->arr[rightChild] > this->arr[max] :
                        rightChild < this->SIZE && this->arr[rightChild] < this->arr[max]) {
                max = rightChild;
            }

            // If max or min is now not the root (swapping action)
            if (max != i) {
                T temp = this->arr[i];
                this->arr[i] = this->arr[max];
                this->arr[max] = temp;

                // Update i = max for recursion (to see if the next sub-tree > current max)
                // Or update i = max to see if next sub-tree < current min
                i = max;
            }
            else break; // max is now i which satisfies the condition (no more recursion needed)
        }
    }
}
template <typename T>
void Heap<T>::setMinMax(bool isMax)
{
    this->isMax = isMax;
    if (this->SIZE != 0) heapify();
}
template <typename T>
const DArray<T> Heap<T>::getDArray()
{
    DArray<T> array;
    for (int i = 0; i < this->SIZE; i++) {
        T temp = this->arr[i];
        array.push_back(temp);
    }
    
    return array;
}

// Explicit instantiations
template class Heap<int>;
template class Heap<float>;
template class Heap<double>;
template class Heap<char>;
// Add more instantiations for other datatypes as needed