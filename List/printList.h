#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

ListNode* vectorToListNode(vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (auto num : nums) {
        if (head == nullptr) {
            // 如果是第一个元素，创建头节点
            head = new ListNode(num);
            tail = head;
        } else {
            // 否则，在尾部添加新节点
            tail->next = new ListNode(num);
            tail = tail->next;
        }
    }
    return head;
}



void printList(ListNode* head){
    while(head){
        cout<<head->val;
        if(head->next)cout<<"->";
        head = head->next;
    }
    cout<<endl;
}

