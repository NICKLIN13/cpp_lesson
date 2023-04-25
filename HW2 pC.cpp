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
    cout << "\n";
    
    // nested vector
    vector<vector<string>> lists(3, {"12", "ab"});
    for (int j = 0; j < lists.size(); j++) {
        cout << j << "\n";
        for (int i = 0; i < lists[j].size(); i++) {
            cout << lists[j][i] << "\n";
        }
        cout << "\n";
    }
}