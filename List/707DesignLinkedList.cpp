#include <iostream>
#include <vector>
#include "printList.h"
using namespace std;


class MyLinkedList {
public:
    MyLinkedList() {
        dummyHead = new ListNode(INT_MIN, nullptr);
        size_ = 0;
    }

    int get(int index) {
        if(index < 0 || index > (size_ - 1)) return -1;
        ListNode* node = dummyHead->next;
        while(index--){
            node = node->next;
        }
        return node->val;
    }
    
    void addAtHead(int val) {  
        ListNode* newnode = new ListNode(val);
        newnode->next = dummyHead->next;
        dummyHead->next = newnode;
        size_++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* tail = dummyHead;
        for(int i = 0; i<size_; i++) tail = tail->next;
        tail->next = newNode;
        size_++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size_ ) return;  
        if(index < 0) index = 0;

        ListNode* node = dummyHead;
        for(int i = 0; i<index; i++) node = node->next;
        ListNode* tmp = node->next; 
        ListNode* newnode = new ListNode(val, tmp); 
        node->next = newnode;
        size_++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size_ ) return;
        ListNode* node = dummyHead;
        for(int i = 0; i<index; i++) node = node->next;
        node->next = node->next->next;
        size_--;
    }
private:
   ListNode* dummyHead;
   int size_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main(){
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2);    // linked list becomes 1->2->3
    int res = myLinkedList->get(1);    // return 2
    myLinkedList->deleteAtIndex(1);    // now the linked list is 1->3
    int res2 = myLinkedList->get(1);   //return 3
    cout<<"res : "<<res<<" res2 : "<<res2<<endl;
    return 0;

}