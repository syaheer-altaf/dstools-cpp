/*
======================================================================
    Header file containing node interfaces.
    [used for any data structures containing nodes]
    Author(s): Mohamed Syaheer Altaf
======================================================================
*/
#ifndef DSNODE_HPP
#define DSNODE_HPP

#include <memory>

namespace DSTools
{

template <typename T>
struct Node
{
T value = T();
std::shared_ptr<Node<T>> nextNode = nullptr;
std::shared_ptr<Node<T>> leftChild = nullptr;
std::shared_ptr<Node<T>> rightChild = nullptr;
};

}

#endif /*DSNODE_HPP*/