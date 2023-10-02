#include <iostream>
#include <string>

using namespace std;

int main() {
  string str = "";
  string rev = "";
  cin >> str;
  for (int i = str.length(); i >= 0; i--) {
    rev = rev + str[i];
  }
  cout << rev << endl;
  return 0;
}