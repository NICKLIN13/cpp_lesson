#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_routes(vector<vector<int>> routes) {
        for (int i = 0; i < routes.size(); i++) {
        for (int j = 0; j < routes[i].size(); j++) {
            cout << routes[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int N = 0, M = 0, R = 0;
    cin >> N >> M;
    cin >> R;

    // Read inputs
    vector<vector<int>> routes(R, {0, 0});
    for (int i = 0; i < routes.size(); i++) {
        cin >> routes[i][0] >> routes[i][1];
    }

    // Confirm inputs // TEST
    cout << "\n";
    cout << "N=" << N << ", M=" << M << "\n";
    print_routes(routes);

    // Sort routes
    sort(routes.begin(), routes.end());
    print_routes(routes); // TEST

    // Count the valid routes of each combination
        // Generate all combinations?
        // Examine valid routes
            // Define is_valid()

    // Find the max count


}