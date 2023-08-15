#include <iostream>
// how to debug?? // TODO

#define NULL 0

using namespace std;
// 0123456
// abcdef
// ^     $
class Stack {
private:
    int arr[100] = {NULL};
    int size = 0;

public:
    bool empty() {
        return size == 0;
    }

    void push(int num) {
        arr[size] = num;
        size++;
    }
    void pop() {// check empty
        if (empty()) return;

        arr[size-1] = NULL;
        size--;
    }

    int top() {
        if (empty()) return;
        return arr[size-1];
    }

    void print() {
        // string res; // result
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

// 0123456789
//  bcdefg
//  ^     $
class Queue {
private:
    int arr[100] = {NULL};
    int head = 0, tail = 0;

public:

    bool empty() {
        return size == 0;
    }

    void push(int num) {
        arr[tail] = num;
        tail++;
    }
    void pop() {
        if (empty()) return;
        arr[head] = NULL;
        head++;
    }

    int top() {
        if (empty()) return;
        return arr[tail-1];
    }

    void print() {
        // string res; // result
        for (int i = head; i < tail; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    int size() {
        return tail - head;
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