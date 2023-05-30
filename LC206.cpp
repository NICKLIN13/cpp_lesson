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
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return NULL;
        ListNode *cur = head, *prev = nullptr, *nxt = head->next;
        while(cur != NULL) {
          cur->next = prev;
          prev = cur;
          cur = nxt;
          nxt = nxt->next;
        }
        return prev;
    }
};

void buildList(vector<int> nums) {

}

void printList() {
}

int main() {
    vector<int> nums;
    int N = 10;
    for (int i = 0; i < N; i++) {
        nums.push_back(i);
    }

    Solution s;
    buildList(nums);
    // printList(root);


}