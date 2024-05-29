#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <ListNode.h>
#include <vector>
#include <stdexcept>

template<typename T>
class LinkedList{
private:
    ListNode<T> *head;
    ListNode<T> *tail;
    int size;

    //Error checking
    bool isValidIndex(int index) const { return ((index >=0) && (index < size)); }
    bool isValidPosition(int index) const { return ((index >=0) && (index <=size)); }
    bool isEmpty() const {return size<=0;}
    void checkIndex(int index) const{
        if(!isValidIndex(index))
            throw std::out_of_range("Index" + std::to_string(index) + " is out of bounds");
    }
    void checkPosition(int pos) const {
        if(!isValidPosition(pos))
            throw std::out_of_range("Position" + std::to_string(pos) + " is out of bounds");
    }
    void checkEmpty() const {
        if(isEmpty())
            throw std::out_of_range("List is empty");
    }

public:
    //Initialize
    LinkedList(){
        head = new MyListNode<T>();
        tail = new MyListNode<T>();
        head->next = tail;
        tail->prev = head;
    }
    LinkedList( std::vector<T> *list){
        int size = list.size();
        if(size == 0) return;
        
        ListNode<T> *cur = head;
        for( int i = 0; i < size;i++){
            ListNode<T> *new_node = new ListNode<T>(list[i]);
            cur->next = new_node;
            new_node->prev = cur;
            cur = new_node;
        }
        cur ->next = tail;
        tail->prev = cur;
    }
    //Access
    ListNode<T>* getNode(int index) const {
        checkIndex(index);
        if(index < (size-1)/2){
            ListNode<T> *cur = head->next;
            for(int i=0; i<index; i++){
                cur = cur->next;
            }
            return cur;
        } else {
            index = size - 1 - index;
            ListNode<T> *cur = tail->prev;
            for(int i=0; i<index; i++){
                cur = cur->prev;
            }
            return cur;
        }
    }
    T get(int index) const {
        ListNode<T> *cur = getNode(index);
        return cur->value;
    }

    T getFirst() const {
        checkEmpty();
        return head->next->value;
    }

    T getLast() const {
        checkEmpty();
        return tail->prev->value;
    }

    //Add
    void add(int pos, T value) {
        checkPosition(pos);
        if(size == pos){
            addLast(value); //To prevent fetch head->prev, which is a nullptr
            return;
        }
        ListNode<T> *cur = getNode(pos);
        cur = cur->prev; //move to the previous one to add a new node at the position of index.
        ListNode<T> *new_node = new ListNode<T>(value);
        new_node->next = cur->next;
        cur->next = new_node;
        new_node->prev = cur;
        new_node->next->prev = new_node;
        size++;
    }

    void addFirst(T value) {
        ListNode<T> *new_node = new ListNode<T>(value);
        new_node->next = head->next;
        head->next = new_node;
        new_node->prev = head;
        new_node->next->prev = new_node;
        size++;
    }

    void addLast(T value) {
        ListNode<T> *new_node = new ListNode<T>(value);
        new_node->prev = tail->prev;
        tail->prev = new_node;
        new_node->next = tail;
        new_node->prev->next = new_node;
        size++;
    }

    //Remove
    void remove(int index){
        ListNode<T> *cur = getNode(index);
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        size--;
    }

    void removeFirst(){
        checkEmpty();
        ListNode<T> *temp = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        delete temp;
        size--;
    }

    void removeLast(){
        checkEmpty();
        ListNode<T> *temp = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        delete temp;
    }

    //modify
    void set(int index, T value){
        ListNode<T> *cur = getNode(index);
        cur->value = value;
    }
};
#endif