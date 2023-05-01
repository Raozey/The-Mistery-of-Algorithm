#include <iostream>
#include <vector>
#include "printList.h"
using namespace std;




ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur != nullptr){
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = vectorToListNode(nums);
    head = reverseList(head);

    printList(head); //5->4->3->2->1

    return 0;
}