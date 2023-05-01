#include <iostream>
#include <vector>
#include "printList.h"
using namespace std;


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyhead = new ListNode(INT_MAX, head);
    ListNode* slow = dummyhead;
    ListNode* fast = dummyhead;
    while(n--) fast = fast->next;

    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    // 此时slow指向要删除节点的前一个节点
    // slow->next = slow->next->next;

    // 清理内存的做法
    ListNode* tmp = slow->next;
    slow->next = tmp->next;
    delete tmp;

    return dummyhead->next;
}


int main(){
    vector<int> nums = {1,2,3,4,5,6,42,7};
    ListNode* head = vectorToListNode(nums);
    head = removeNthFromEnd(head, 2);

    printList(head); //1->2->3->4->5->6->7

    return 0;
}


