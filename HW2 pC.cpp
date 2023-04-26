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

bool is_valid(vector<int> p, vector<int> q) {
    // p_start <= q_start AND p_end < q_end
    return (p[1] <= q[1] && p[0] < q[0]);
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
    // 1. Choose a route as the first one
    for (int i = 0; i < routes.size(); i++) {
        vector<vector<int>> combination;
        combination.push_back(routes[i]);
    }

    // 2. Add another new route, one by one
    // 3. Examine if the new route is valid
        // Define is_valid() // DONE
        // Compare the new route with the previous route
    // 4. Find the max count


}