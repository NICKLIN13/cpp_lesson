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
p c n
c>p;
p=c;
c=n;
n=n->next;

p
  c
    n
N 0>1>2>N
N<0 1>2>N
N<0<1 2>N
N<0<1<2 N

*/
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return NULL;
        ListNode *cur = head, *prev = nullptr, *nxt = head->next;
        while(cur != nullptr) {
          cur->next = prev;
          prev = cur;
          cur = nxt;
          if (nxt != nullptr) {
            nxt = nxt->next; // ?!
            cout << prev->val << " ";
            cout << cur->val << " ";
            cout << nxt->val << "\n";
          }
        }
        return prev;
    }
};

ListNode* buildList(const vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return head;
}

void printList(ListNode* head) {
    auto curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    vector<int> nums;
    int N = 10;
    for (int i = 0; i < N; i++) {
        nums.push_back(i);
    }

    Solution s;
    ListNode* root = buildList(nums);
    printList(root);
    root = s.reverseList(root);
    // printList(root);


}