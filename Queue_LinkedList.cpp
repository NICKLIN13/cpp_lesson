#include <iostream>
using namespace std;

struct Node {
  int val;
  struct Node* next;
};

struct Node* front = nullptr;
struct Node* rear = nullptr;

void enqueue(int y) {
  struct Node* temp = new Node(); // 先創建一個新節點，新節點的位址用temp存著
  temp->val = y; // 在新節點的val裡面放入y值
  temp->next = nullptr; // 新節點要指向nullptr（因為他是這個List的最後一個節點，enqueue都往後面放）


  // 接下來會有兩種情況
  // 情況1. queue裡面什麼都還沒有
  if(front == nullptr && rear == nullptr) { // front跟rear都等於nullptr的時候，代表這個queue裡面什麼都還沒有
    front = rear = temp; // 就可以把這兩個指標都存新節點的位址
    return; // return之後temp就被清除了，節點的位址也都已經記在front跟rear裡面
  }

  // 情況2. queue裡面已經有東西了
  rear->next = temp; // rear是個位址，他現在存的是一個節點的位址，這個動作等於是把這個節點裡的next，存『新節點的位址』，讓這個節點連上新節點
  rear = temp;
}


void dequeue() {
  struct Node* temp = front; // 先創立一個temp指標，temp指著的東西就是等等要刪掉的

  if(front == nullptr) return ; // 如果front是空的，代表queue裡面什麼都沒有，不能dequeue，直接return

  
  if(front == rear) {
    front = rear = nullptr;
  } else {
    front = front -> next; // 為什麼要先用temp記著要刪除的東西呢？ 因為在刪除之前我們就會先把front移到下一個節點上，如果沒有先記著，就找不到我們要刪除的東西了
  }
  delete temp; // 現在front移走了，我們還是找得到要刪除的節點（因為有用temp先記著），就可以放心刪掉了
}


int main() {
  enqueue(23);
  enqueue(18);
  enqueue(75);
  // 到目前這一步，queue裡面應該是  23 - 18 - 75 - nullptr
  // 如果dequeue，刪除的會是最先放進來的23，然後front會指到23的下一個節點（18）上面

  dequeue();
  cout << front -> val << endl; // 18（因為23被刪除了） 
  cout << rear -> val << endl; // 75（rear會指在最後一個元素上）
  return 0;
}