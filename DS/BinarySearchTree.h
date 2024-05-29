#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "Node.h"
#include "BinaryTree.h"
using namespace std;
/*
TODO:
1. remove
2. Invert
3. Find
*/

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
protected:
    using BinaryTree<T>::root;
    void BSTinsert(T value){
        Node<T>* prev = nullptr;
        Node<T>* cur = this->root;
        while(cur != nullptr){
            prev = cur;
            if(value > cur->value){
                cur = cur->rightChild;
            } else if (value < cur->value){
                cur = cur->leftChild;
            } else {
                return; 
            }
        }
        if (prev == nullptr) { 
            this->root = new Node<T>(value);
        } else if (value < prev->value) {
            prev->leftChild = new Node<T>(value);
        } else {
            prev->rightChild = new Node<T>(value);
        }
    }

    
public:
    using BinaryTree<T>::BinaryTree;
    using BinaryTree<T>::inorder;   // Brings the inorder method from the base class into scope
    using BinaryTree<T>::preorder;  // Brings the preorder method from the base class into scope
    using BinaryTree<T>::postorder; // Brings the postorder method from the base class into scope

    void insert(T value) override {
        BSTinsert(value);
    }
};



#endif