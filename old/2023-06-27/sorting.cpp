#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<T> &v) {

    // for (i: n-1 ~ 0)
    //     for (j: 0 ~ i-1)
    //          if (v[j] > v[j+1])
    //              swap(v[j], v[j+1]);
    int n = v.size();
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= i-1; j++) {
            // if (less(v[j+1], v[j]))
            if (v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                print(v);
                }
        }
    }
}

void insertion_sort(vector<int> &v) {

/*
 i
28517
 j

25817
25187
21587
12587
(x,y)
3,1
1,2

    i
12587
12578

*/
    // for (i: 1 ~ n-1)
    //     for (j: i ~ 1)
    //          if (v[j] < v[j-1])
    //              swap(v[j], v[j-1]);
    int n = v.size();
    for (int i = 1; i <= n-1; i++) {
        for (int j = i; j >= 1; j--) {
            if (v[j] < v[j-1]){
                swap(v[j], v[j-1]);
                print(v);
                }
        }
    }
}

// less ?
bool compartor(date a, date b) {
    if (a.y < b.y) return true

}

int main() {
    // cout << "Hello World!\n";
    vector<int> v = {-3, 6, 5, -1, 0, 9, 3};
    print(v);
    bubble_sort(v);
    // sort(v.begin(), v.end(), compartor);
    print(v);

    // stable
    // node_1(1) // node_2(1)
    // AabcCB
    // AaBbCc
    // 1234567

    //i    v
    // 01234567
    // a
    //j    ^
    
    // 01234

    // 28517
    // 28517
    // 25817
    // 25187
    // 25178
    // 25178
    // 25178
    // 21578
    // 21578
    // 12578




/*
5
adfbaldf01234556789



*/
}