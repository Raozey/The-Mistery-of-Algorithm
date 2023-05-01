#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // 快慢指针相遇，说明存在环
            return true;
        }
    }
    return false; // 遍历结束，未发现环
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
    bool result1 = hasCycle(head1);
    cout << "Result 1: " << result1 << endl; // 应该输出 0

    // 构造一个有环的链表
    ListNode *head2 = new ListNode(1);
    ListNode *node5 = new ListNode(2);
    ListNode *node6 = new ListNode(3);
    ListNode *node7 = new ListNode(4);
    head2->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node5; // 添加一个环
    bool result2 = hasCycle(head2);
    cout << "Result 2: " << result2 << endl; // 应该输出 1

    return 0;
}