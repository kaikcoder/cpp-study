#include <bits/stdc++.h>
using namespace std;

/*
解题思路:
    1.逐位相加
        -同步遍历两个链表设当前分别为x,y，计算sum = x + y + carry.
         当前位的结果为sum % 10，更新carry = sum / 10。
    2.构造新链表
        -用一个哑节点dummy方便操作，尾指针cur指向结果链表的最后一个节点
        -每次cur->next = new ListNode(sum % 10),然后cur = cur->next
    3.后处理
    4.返回
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x=0): val(0),next(nullptr); // 初始化列表
}

class Solution{
    public:
        ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
            ListNode dummy; // 哑节点
            ListNode* cur = &dumpy; // 尾指针
            int carry = 0; // 进位

            // 同时遍历l1,l2
            while(l1 || l2 || carry){
                int x = (l1 ? l1->val : 0);
                int y = (l2 ? l2->val : 0);
                int sum = x + y + carry;
                carry = sum / 10;
                cur->next = new ListNode(sum % 10);
                cur = cur ->next;
                if(l1) l1 = l1->next;
                if(l2) l2 = l2->next;
            }
            return dummy.next;
        }
};

// 辅助：从 vector 构造链表，返回头指针
ListNode* makeList(const vector<int>& a) {
    ListNode dummy;
    ListNode* cur = &dummy;
    for (int x : a) {
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return dummy.next;
}

// 辅助：打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 示例测试：(2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
    vector<int> a1 = {2,4,3};
    vector<int> a2 = {5,6,4};
    ListNode* l1 = makeList(a1);
    ListNode* l2 = makeList(a2);

    cout << "输入链表1: ";
    printList(l1);
    cout << "输入链表2: ";
    printList(l2);

    Solution sol;
    ListNode* res = sol.addTwoNumbers(l1, l2);

    cout << "输出结果 : ";
    printList(res);

    return 0;
}