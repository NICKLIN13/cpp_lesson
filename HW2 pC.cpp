#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N = 0, M = 0, R = 0;
    cin >> N >> M;
    cin >> R;

    // nested vector
    vector<vector<int>> routes(R, {0, 0});
    for (int i = 0; i < routes.size(); i++) {
        cin >> routes[i][0] >> routes[i][1];
    }

    cout << "\n";

    cout << "N=" << N << ", M=" << M << "\n";

    for (int i = 0; i < routes.size(); i++) {
        for (int j = 0; j < routes[i].size(); j++) {
            cout << routes[i][j] << " ";
        }
        cout << "\n";
    }
}