/*////////////////////////////////////////////////////////
    DYNAMIC ARRAY
    Author(s): Mohamed Syaheer Altaf
    -----------------------------------------------------
    SOME IMPORTANT NOTE FOR DYNAMIC ARRAY:
    1) Array has two important parameters:
		a) Capacity: this represents the size of the whole container and it changes dynamically.
		b) Size: this represents the size of the desired array which is the subset of the container.
    2) When to change the size of the container dynamically:
		a) If size == (capacity/2) => capacity is halved. The container shrinks.
		b) If size >= capacity     => capacity is doubled. The container grows.
	3) Make sure to always free up the memory space if not needed.

*/////////////////////////////////////////////////////////

#include "DSArray.hpp"
using namespace DSTools;

/*Dynamic Array Implementation*/
// Constructor
template <typename T>
DArray<T>::DArray()
{
	CAPACITY = 1;
	SIZE = 0;
	arr = new T[CAPACITY];
}
template <typename T>
DArray<T>::DArray(const DArray<T>& obj)
{
	*this = obj;
}
// Destructor (free space)
template <typename T>
DArray<T>::~DArray()
{ 
	delete[] arr; 
}
// Methods
template <typename T>
int DArray<T>::size()
{ 
	return SIZE; 
}
template <typename T>
void DArray<T>::doubleCapacity()
{
	CAPACITY = CAPACITY * 2;		// doubles the capacity of the array. (grows)
	T* temp = new T[CAPACITY];   //  dynamically allocate memory of new capacity.

	// Copy the contents of old array
	for (int i = 0; i < SIZE; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;				// delete old array			
	arr = temp;					// assign new array
}
template <typename T>
void DArray<T>::halfCapacity()
{
	CAPACITY = 0.5 * CAPACITY + 1;		// halves the capacity of the array. (shrinks)
	T* temp = new T[CAPACITY];		// dynamically allocate memory of new capacity.

	// Copy the contents of old array
	for (int i = 0; i < SIZE; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;		// delete old array
	arr = temp;			// assign new array
}
template <typename T>
void DArray<T>::push_back(T value)
{
	// condition to double the capacity
	if (SIZE == CAPACITY) {
		doubleCapacity();
	}
	arr[SIZE] = value;
	SIZE++;				// keeps track of the current size
}
template <typename T>
T DArray<T>::pop_back()
{
	if (SIZE == 0) return T();	// Default constructed value of DT.

	T temp = arr[SIZE - 1];
	arr[SIZE - 1] = T();		// pops the element of last index, and replace with default value.
	SIZE--;						// keeps track of the current size.

	// condition to halve the capacity
	if (SIZE == (CAPACITY / 2)) {
		halfCapacity();
	}

	return temp;
}

// Explicit instantiations
template class DArray<int>;
template class DArray<float>;
template class DArray<double>;
template class DArray<char>;
// Add more instantiations for other datatypes as needed