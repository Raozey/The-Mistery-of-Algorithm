#include <iostream>
#include "printList.h"
using namespace std;

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) break;
    }
    if(fast == nullptr || fast->next == nullptr) return nullptr;

    ListNode *res = head;
    while(res != fast){
        res = res->next;
        fast = fast->next;
    }
    return res;
}


int main() {
    // 构造一个没有环的链表
    ListNode *head1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    head1->next = node2;
    node2->next = node3;
    node3->next = node4;
    ListNode *result1 = detectCycle(head1);
    cout << "Result 1: " << (result1 == nullptr ? "no" : "yse" )<< endl; // 应该输出 0

    // 构造一个有环的链表
    ListNode *head2 = new ListNode(1);
    ListNode *node5 = new ListNode(2);
    ListNode *node6 = new ListNode(3);
    ListNode *node7 = new ListNode(4);
    head2->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node5; // 添加一个环
    ListNode *result2 = detectCycle(head2);
    cout << "Result 2: " << (result2 == nullptr ? "no" : "yse" ) << endl; // 应该输出 1

    return 0;
}