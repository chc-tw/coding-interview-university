#ifndef BINARY_TREE_ARR_H_
#define BINARY_TREE_ARR_H_
#include <vector>
template<typename T>
class BinaryTreeArr{
protected:
    vector<T> tree;
    int root_index = -1;
public:
    BinaryTreeArr(){}
    BinaryTreeArr(vector<T> tree): tree(tree){root_index = 0;}
    ~BinaryTreeArr(){}
    int parent_index(int index) const { return (index-1)/2;}
    int left_index(int index) const { return index * 2 + 1;}
    int right_index(int index) const { return index * 2 + 2;}
};

#endif