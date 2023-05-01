#include <iostream>
#include <vector>
#include "printList.h"
using namespace std;


// 使用双指针，pre + cur
ListNode* removeElements2(ListNode* head, int val){
    ListNode* dummyHead = new ListNode(INT_MAX, head);
    ListNode* pre = dummyHead;
    ListNode* cur = head;
    while(cur){
        if(cur->val == val){
            pre->next = cur->next;
            cur = cur->next;
        }
        else{
            pre = pre->next;
            cur = cur->next;
        }
    }
    return dummyHead->next;
}
// 使用单指针，从dummyhead开始
ListNode* removeElements(ListNode* head, int val){
    ListNode* dummyHead = new ListNode(INT_MAX, head);
    ListNode* cur = dummyHead;
    while(cur->next){
        if(cur->next->val == val){
            cur->next = cur->next->next;
        }
        else cur = cur->next;
    }
    return dummyHead->next;
}



int main(){

    vector<int> nums = {1,2,6,3,4,5,6};
    ListNode* head = vectorToListNode(nums);
    printList(head);

    head = removeElements(head,6);
    printList(head);
    return 0;
}