#include <iostream>

#define NULL 0

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Queue {
private:
    ListNode *head = new ListNode();
    ListNode *tail = head;


public:
    void push(int num) {
        ListNode *newNum = new ListNode(num, nullptr);
        tail -> next = newNum;
        tail = newNum;
    }

    void pop() {
        // pop
        // h->N
        if (empty()) return; // Check if empty
        ListNode *temp = head->next;
        head->next = temp->next;
        delete temp;
    }

    int top() {
        if (empty()) return; // Check if empty
        return head->next->val;
    }

    bool empty() {
        return head->next == nullptr;
    }

    void print() {
        ListNode *curr = head->next;

        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
    }

    int size() {
        int count = 0;
        ListNode *curr = head->next;

        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
};


// h->N
// h->a->b->c->N
//          t

//    t
// a->b  c->N  // del c;
//    V
//    N


class Stack {
private:
    ListNode *head = new ListNode();
    ListNode *tail = head;


public:

    bool empty() {
        return head->next == nullptr;
    }

    void push(int num) {
        ListNode *newNum = new ListNode(num, nullptr);
        tail -> next = newNum;
        tail = newNum;
    }

    void pop() {
        if (empty()) return;
        // How to set new tail?

        ListNode *prev = head;
        // abcde
        // head -> ... -> prev -> tail


        // while (true) {
        //     if (prev->next == tail) {
        //         break;
        //     }
        //     prev = prev->next;
        // }

        while (prev->next != tail) {
            prev = prev->next;
        }


        // for (prev = head; prev->next == tail; prev = prev->next){}

        // pop
        prev->next = nullptr;
        delete tail;
        tail = prev;
    }

    int top() {
        if (empty()) return;
        return tail->val;
    }

    void print() {
        ListNode *curr = head->next;

        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
    }

    int size() {
        int count = 0;
        ListNode *curr = head->next;

        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
};


int main() {
    bool debug = false;
    Queue s;
    s.push(123);
    s.push(456);
    s.print();

    int a = s.top();

    if (debug) {
        cout << "top=" << a << "\n";
    }
    // define

    s.pop();
    s.print();

    s.push(456);
    s.push(2384);
    s.pop();
    s.push(45612312);
    s.print();

    return 0;
}