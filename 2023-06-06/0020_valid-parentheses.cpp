#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

12341230123456789
       ^
                ^

      0
     1 2
    34 56
   789

class Stack {
private:
    vector<int> v;
public:

    int top() {
        if (empty()) return NULL;
        int sz = v.size();
        return v[sz-1];
    }

    void pop() {
        v[0] = 0
        begin++
        v.erase()
    }

    void push(int n) {
        v[end] = n
        end++
        v.push_back(n)
    }

    bool empty() {
        return size() == 0;
    }

    int size();
};


// interface
// int add(int a, int b)
// int minus(int a, int b)

// [0123]
// num = stack.pop()
// 0020_valid-parentheses
class Solution {
public:
    stack<int> s;
    void f() {
        s.[][()]
    }
    // bool isValid(string s) {
        
    // }
};


