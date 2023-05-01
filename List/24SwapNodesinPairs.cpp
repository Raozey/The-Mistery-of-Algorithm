#include <iostream>
#include <vector>
#include "printList.h"
using namespace std;




ListNode* swapPairs(ListNode* head) {
    ListNode* dummyHead = new ListNode(INT_MIN, head);
    ListNode* pre = dummyHead;
    while(pre->next != nullptr && pre->next->next != nullptr){
        ListNode* mid = pre->next;
        ListNode* cur = pre->next->next;
        ListNode* tmp = cur->next;
        pre->next = cur;
        cur->next = mid;
        mid->next = tmp;
        //更新
        pre = mid;
    }
    return dummyHead->next;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = vectorToListNode(nums);
    head = swapPairs(head);

    printList(head); //2->1->4->3->5

    return 0;
}