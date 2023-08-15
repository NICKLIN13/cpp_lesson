#include <algorithm>
#include <iostream>
#include <vector>

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

void bubble_sort(vector<int> &v) {
  int n = v.size();
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= i - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
  

  // for (i: n-1 ~ 0)
  //     for (j: 0 ~ i-1)
  //          if (v[j] > v[j+1])
  //              swap(v[j], v[j+1]);
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

int main() {
  // cout << "Hello World!\n";
  vector<int> v = {-3, 6, 5, -1, 0, 9, 3};
  print(v);
  // bubble_sort(v);
  insertion_sort(v);
  print(v);
}