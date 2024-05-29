#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <ListNode.h>
#include <vector>

template<typename T>
class LinkedList{
private:
    ListNode<T> *head;
    ListNode<T> *tail;
    int size;
    LinkedList(){
        head->next = tail;
        tail->prev = head;
    }
    LinkedList( vector<T> *list){
        int size = list.size();
        if(size == 0) return;
        
        ListNode<T> *cur = head;
        for( int i = 0; i < size;i++){
            ListNode<T> new_node = new ListNode<T>(list[i]);
            cur->next = new_node;
            new_node->prev = cur;
            cur = new_node;
        }
        cur ->next = tail;
        tail->prev = cur;
    }

    //Error checking
    bool isEmpty() const { return(size == 0); }
    
    //Accessors
    ListNode<T> * get(int index) const {
        ListNode<T> *cur = head->next;
        for(; cur!=nullptrl; cur = cur->next){

        }
    }
};
#endif