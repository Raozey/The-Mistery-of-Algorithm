#include <iostream>
#include <vector>
#include <unordered_set>
#include "printList.h"
using namespace std;





ListNode *getIntersectionNodeHash(ListNode *headA, ListNode *headB) {
    //哈希表
    unordered_set<ListNode *> setA;
    while(headA) {
        setA.insert(headA);
        headA = headA->next;
    }
    while(headB){
        if(setA.find(headB) != setA.end()) return headB;
        headB = headB->next;
    }
    return nullptr;
}
int getLength(ListNode *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    if(lenB > lenA){
        swap(lenA, lenB);
        swap(headA, headB);
    }
    int gap = lenA - lenB;
    while(gap--) headA = headA->next;

    while(headA){
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;   
}

int main() {
    // 构建测试链表A：1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // 构建测试链表B：10 -> 9 -> 8 -> 4 -> 5 -> nullptr
    ListNode *headB = new ListNode(10);
    headB->next = new ListNode(9);
    headB->next->next = new ListNode(8);
    headB->next->next->next = headA->next->next->next;
    headB->next->next->next->next = headA->next->next->next->next;

    // 执行函数并输出结果
    ListNode *intersectionNode = getIntersectionNode(headA, headB);
    if (intersectionNode) {
        cout << "Intersection node value: " << intersectionNode->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    return 0;
}