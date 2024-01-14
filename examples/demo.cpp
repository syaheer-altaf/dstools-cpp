#include "DSArray.hpp"
#include "DSHeap.hpp"
#include "DSHeapSort.hpp"
#include "DSBubbleSort.hpp"
#include "DSMergeSort.hpp"

#include "DSList.hpp"
#include <iostream>

using namespace DSTools;

int main()
{
    Heap<int> arr;
    DArray<int> arr_cpy;

    arr.push_back(300);
    arr.push_back(-50);
    arr.push_back(76);
    arr.push_back(-70);
    arr.push_back(-1000);

    arr_cpy = arr.getDArray();

    std::cout << std::endl;
    std::cout << "Original heap: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr = HeapSort<int>(arr, true)();
    std::cout << "heap sort (max): ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr = HeapSort<int>(arr, false)();
    std::cout << "heap sort (min): ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    arr_cpy = BubbleSort<int>(arr_cpy, true)();
    std::cout << "bubble sort (max): ";
    for (int i = 0; i < arr_cpy.size(); i++) {
        std::cout << arr_cpy[i] << " ";
    }
    std::cout << std::endl;

    arr_cpy = MergeSort<int>(arr_cpy, false)();
    std::cout << "merge sort (min): ";
    for (int i = 0; i < arr_cpy.size(); i++) {
        std::cout << arr_cpy[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "-------------------------------------------------" << std::endl;
    List<int> list;

    list.push_back(300);
    list.push_back(-50);
    list.push_back(76);
    list.push_back(-70);
    list.push_back(-1000);

    std::cout << "Original List: ";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << " -> ";
    }
    std::cout << "NULL" << std::endl;
    return 0;
}