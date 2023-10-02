#include<iostream>
#include<vector>

using namespace std;



void print(const vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}


int main() {
  vector<int> v = {1, 2, 3};
  print(v);

  int x = __cplusplus;
  cout << x << endl;
  return 0;
}