#ifndef NODE_H_
#define NODE_H_

template <typename T>
struct Node
{
    Node* parent;
    Node* leftChild;
    Node* rightChild;
    T value;

    Node(T value) : value(value),  parent(nullptr), leftChild(nullptr), rightChild(nullptr) {}
};

#endif