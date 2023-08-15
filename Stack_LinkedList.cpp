#include <iostream>
using namespace std;

struct Node {
  int val;
  struct Node* link;
};

// top -> nullptr;

struct Node* top = nullptr;

// top -> x -> nullptr

void push(int x) {
  struct Node* temp = new Node(); // 先創一個新的節點（用來放push進去的值），這個節點用temp指著
  temp->val = x; // 把temp指到的地方（就是新節點）的val放入x
  temp->link = top; // 我們要把新節點放到top目前指到的節點的前面，所以把top（top是個位址） 記到新節點的link裡面，讓他連上下一個節點
  top = temp; // 最後再把新節點的位址記到top，讓top指著新節點，把他們連起來，就實現了插入
}

// top -> nullptr

void pop() {
  struct Node* temp; // 先建一個新指標，用來指著我們要刪掉的元素（因為是stack，所以就是top指著的元素）
  temp = top; // 果不其然，把top的位址記錄到temp裡面，等著被刪除
  top = top->link; // temp可以刪除了，但top怎麼辦呢？ top->link裡面存著的是『 top指到的節點裡存的link = 也就是下一個節點的位址 』，所以這個動作是用top去記下一個節點的位址
  delete temp; // 沒有temp的事了，可以刪掉了
}

int main() {
  push(37);
  push(26);
  pop();
  // cout << top->val << ", " << top->link->val << endl;
  cout << top->val << endl;
  return 0;
}