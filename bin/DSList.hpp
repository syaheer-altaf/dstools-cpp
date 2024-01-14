/*
======================================================================
    Header file containing linked interfaces.
    Author(s): Mohamed Syaheer Altaf
======================================================================
*/
#ifndef DSLIST_HPP
#define DSLIST_HPP

#include "DSNode.hpp"
#include <memory>
#include <stdexcept>

using namespace DSTools;

namespace DSTools
{

template <typename T>
class List
{
private:
    std::shared_ptr<Node<T>> head = nullptr;
    int SIZE = 0;
public:
    List();
    List(const List<T>&);
    std::shared_ptr<Node<T>> get();
    T pop_back();
    T pop_front();
    void clear();
    void push_back(T);
    void push_front(T);
    void reverse();
    int size();
    T& operator[](int i)
    {
        if (i > SIZE || i < 0) {
            throw std::out_of_range("Index out of range.");
        }
        std::shared_ptr<Node<T>> temp = head;
        int start = 1;
        while (temp != nullptr) {
            if (start == i + 1) break;
            temp = temp->nextNode;
            start++;
        }
        return temp->value;
    }
    List<T>& operator=(const List<T>& obj)
    {
        if (this != &obj) {
            std::shared_ptr<Node<T>> temp = obj.head;
            this->clear();
            while (temp != nullptr) {
                int val = temp->value;
                this->push_back(val);
                temp = temp->nextNode;
            }
        }
        return *this;
    }

};

}

#endif /*DSLIST_HPP*/