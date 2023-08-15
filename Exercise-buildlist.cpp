// code review
// practice to build list and print it out
// 2023.05.31

#include <iostream>
#include <vector>
using namespace std;

// build a ListNode struct and constructors
// value and a next pointer should be contained
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};


// write a function to buildlist
// return head pointer of the list
ListNode *buildList(const vector<int> nums) {
  // check if vector is valid first
  if (nums.size() == 0) {
    return nullptr;
  }
  // build a head pointer pointing to nums[0]
  ListNode *head = new ListNode(nums[0]);
  // use curr pointer to help us to walk through linked list
  // head pointer must be still, or we'll lose the address where we're from
  ListNode *curr = head;
  for (int i = 1; i < nums.size(); i++) {
    curr->next = new ListNode(nums[i]);
    curr = curr->next;
  }
  return head;
}

// write a function to print out the whole list
void printList(ListNode *head) {
  // check if head pointer is a nullptr first
  // get used to it !!!
  if (head == nullptr) return;

  // why do we need curr pointer here ?
  ListNode *curr = head;
  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  vector<int> nums;
  int N = 4;
  // fill up the vector
  for (int i  = 0; i < N; i++) {
    nums.push_back(i);
  }
  // call buildList function
  // put the pointer just returned by buildList into printList function
  ListNode *head = buildList(nums);
  printList(head);
  return 0;
}