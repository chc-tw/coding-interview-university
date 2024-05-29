#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

template<typename T>
struct ListNode {
    ListNode *next;
    ListNode *prev;
    T value;
    ListNode(){value=0; prev=nullptr; next=nullptr;}
    ListNode(T value) : value(value), next(nullptr), prev(nullptr) {}
};

#endif