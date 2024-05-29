#ifndef MAX_BINARY_HEAP_H_
#define MAX_BINARY_HEAP_H_

#include "BinaryTreeArr.h"
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class MaxBinaryHeap : public BinaryTreeArr<T>{
protected:
    using BinaryTreeArr<T>::tree;
    using BinaryTreeArr<T>::root_index;
    void swim(){
        int cur = tree.size()-1;
        int parent = parent_index(cur);
        while(cur>0 && tree[cur] > tree[parent]){ //make sure cur is not root
            swap(tree[cur],tree[parent]);
            cur = parent;
            parent = parent_index(cur);
        }
    }
    
    void sink(int start, int end) {
    int cur = start;
    while (true) {
        int left = left_index(cur);
        int right = right_index(cur);
        int largest = cur;
        if (left <= end && tree[left] > tree[largest]) 
            largest = left;

        if (right <= end && tree[right] > tree[largest]) 
            largest = right;
        
        if (largest == cur) 
            break;
        
        swap(tree[cur], tree[largest]);
        cur = largest;
    }
}

public:
    using BinaryTreeArr<T>::BinaryTreeArr;
    using BinaryTreeArr<T>::parent_index;
    using BinaryTreeArr<T>::left_index;
    using BinaryTreeArr<T>::right_index;
    void insert(T value){
        tree.push_back(value);
        this->swim();
    }
    T extract_max(){
        swap(tree.front(),tree.back());
        T max_value = tree.back();
        tree.pop_back();
        this->sink(tree.size()-1);
        return max_value;
    }

    size_t size() const { return tree.size(); }

    void display(){
        for(auto& node : tree)
            cout<<node<<" ";
        cout<<endl;
    }

    void sort() {
        int n = tree.size()-1;
        // Build max heap
        for (int i = parent_index(n); i >= 0; i--)
            sink(i, n);

        // Heap sort
        for (int end = n; end > 0;) {
            swap(tree[0], tree[end]); 
            sink(0, --end);   
        }
    }

};
#endif