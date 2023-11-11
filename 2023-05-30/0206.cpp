// [Reverse Linked List - LeetCode](https://leetcode.com/problems/reverse-linked-list/)

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
/*
  h

p c>n>x
p<c n>x
?<p c>n

a->next = b
b
      n
  p<c
N 0>1>2>3>N
N<0 1>2>3>N
N<0<1 2>3>N
N<0<1<2 3>N
N<0<1<2<3 N
        ^

*/

public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr; // NULL == 0; nullptr != NULL
        ListNode *cur = head, *prev = nullptr, *nxt = head->next;
        while(cur != nullptr) {
            nxt = cur->next;

            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

ListNode* buildList(const vector<int> &nums) {
    // if (nums.size() == 0) {
    //     return nullptr;
    // }
    if (nums.empty()) {
        return nullptr;
    }

    // ListNode* head;
    // head->val = nums[0];

    // ListNode root = ListNode(nums[0]);
    // ListNode* head = &root;

    ListNode* head = new ListNode(nums[0]);

    ListNode* curr = head;
    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}


void printList(ListNode *head) {
/*
h
0,1,2,3
^>n
  ^>n
    ^>n
      ^>N
        ^
*/

    if (head == nullptr) return;

    ListNode *curr = head; // what if head is a const???
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        // cout << curr->next->val << "\n"; //

        curr = curr->next;
    }
    cout << "\n";

}

int main() {
    vector<int> nums;
    int N = 4;
    for (int i = 0; i < N; i++) {
        nums.push_back(i); // 0123
    }
    for (int i = 0; i < N; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";

    ListNode* head = buildList(nums);

    printList(head);

    Solution s;
    ListNode* head2 = s.reverseList(head);


    printList(head2);

}

