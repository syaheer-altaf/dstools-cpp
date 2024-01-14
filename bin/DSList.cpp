/*////////////////////////////////////////////////////////
    LINKED LIST
    Author(s): Mohamed Syaheer Altaf
    -----------------------------------------------------
    SOME IMPORTANT NOTE FOR LINKED LIST:

*/////////////////////////////////////////////////////////

#include "DSNode.hpp"
#include "DSList.hpp"

using namespace DSTools;

template <typename T>
List<T>::List()
{
    // do nothing...
}
template <typename T>
List<T>::List(const List<T>& obj) 
{
    *this = obj;
}
template <typename T>
std::shared_ptr<Node<T>> List<T>::get()
{
    std::shared_ptr<Node<T>> temp = head;
    return temp;
}
template <typename T>
T List<T>::pop_back()
{
    if (head == nullptr) return T();
    if (head->nextNode == nullptr) {
        T val = head->value;
        head = nullptr;
        SIZE--;
        return val;
    }
    std::shared_ptr<Node<T>> temp = head;
    int i = 1;
    T val;
    while (true) {
        if (i == SIZE - 1) {
            val = temp->nextNode->value;
            temp->nextNode = nullptr;
            break;
        }
        temp = temp->nextNode;
        i++;
    }
    SIZE--;
    return val;
}
template <typename T>
T List<T>::pop_front()
{
    if (head == nullptr) return T();
    if (head->nextNode == nullptr) {
        T val = head->value;
        head = nullptr;
        SIZE--;
        return val;
    }
    std::shared_ptr<Node<T>> temp = head;
    T val = temp->value;
    temp = temp->nextNode;
    head = nullptr;
    head = temp;

    SIZE--;
    return val;
}
template <typename T>
void List<T>::clear()
{
    int _size = SIZE;
    for (int i = 0; i < _size; i++) {
        this->pop_front();
    }
}
template <typename T>
void List<T>::push_back(T val)
{
    std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>();
    node->value = val;
    if (head == nullptr) {
        head = node;
    }
    else {
        std::shared_ptr<Node<T>> temp = head;
        while (temp->nextNode != nullptr) {
            temp = temp->nextNode;
        }
        temp->nextNode = node;
    }
    SIZE++;
}
template <typename T>
void List<T>::push_front(T val)
{
    std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>();
    node->value = val;
    if (head == nullptr) {
        head = node;
    }
    else {
        node->nextNode = head;
        head = node;
    }
    SIZE++;
}
template <typename T>
void List<T>::reverse()
{
    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> prev = nullptr;
    while (current != nullptr) {
        next = current->nextNode;
        current->nextNode = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
template <typename T>
int List<T>::size()
{ 
    return SIZE; 
}

template class List<int>;
template class List<char>;