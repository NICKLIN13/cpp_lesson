#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // string name;
    // cin >> name;
    // cout << "Hello, " << name << "!" << "\n";

    vector<string> list = {"Hello, ", "Nick!"};
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }

    vector<string> list2(5, "Wow");
    for (int i = 0; i < list2.size(); i++) {
        cout << list2[i] << "\n";
    }
    return 0;
}