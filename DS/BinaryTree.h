#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_
#include "Node.h"
using namespace std;   

template <typename T>
class BinaryTree {
protected:
    Node<T>* root;
    
    void inorder(Node<T>* node) const {
        if(node == nullptr) return;
        inorder(node->leftChild);
        cout<<node->value<<" ";
        inorder(node->rightChild);
        return;
    };
    void preorder(Node<T>* node) const {
        if(node == nullptr) return;
        cout<<node->value<<" ";
        preorder(node->leftChild);
        preorder(node->rightChild);
        return;
    };
    void postorder(Node<T>* node) const{
        if(node == nullptr) return;
        postorder(node->leftChild);
        postorder(node->rightChild);
        cout<<node->value<<" ";
        return;
    };
    void destroyTree(Node<T>* node) const {
        if(node != nullptr){
            destroyTree(node->leftChild);
            destroyTree(node->rightChild);
            delete node;
        }
    }
public:
    BinaryTree() : root(nullptr){}
    BinaryTree(Node<T>* root) : root(root){}
    BinaryTree(T value) : root(new Node<T>(value)){}
    ~BinaryTree(){
        destroyTree(this->root);
    }
    // virtual void insert(T value)=0;
    // virtual void remove(T value)=0;
    virtual void find(T value)=0;
    void inorder() const {
        inorder(root);
    }
    void preorder() const {
        preorder(root);
    };
    void postorder() const {
        postorder(root);
    };
};

#endif