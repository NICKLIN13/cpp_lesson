#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool DEBUG = false;

void print_r(vector<long long> r) {
    cout << r[0] << "," << r[1] << "\n";
}

void print_routes(vector<vector<long long>> routes) {
    for (long long i = 0; i < routes.size(); i++) {
        for (long long j = 0; j < routes[i].size(); j++) {
            cout << routes[i][j] << " ";
        }
        cout << "\n";
    }
}

bool is_valid(vector<long long> p, vector<long long> q) {
    // p_start < q_start AND p_end < q_end
    return (p[1] < q[1] && p[0] < q[0]);
}

int main() {
    // DEBUG = true;
    long long N = 0, M = 0, R = 0;
    cin >> N >> M;
    cin >> R;

    // Read inputs
    vector<vector<long long>> routes(R, {0, 0});
    for (long long i = 0; i < routes.size(); i++) {
        cin >> routes[i][0] >> routes[i][1];
    }

    // Confirm inputs
    if (DEBUG) {
        cout << "\n";
        cout << "N=" << N << ", M=" << M << "\n";
        print_routes(routes);
    }

    // Sort routes
    sort(routes.begin(), routes.end());
    if (DEBUG) print_routes(routes);

    // Count the valid routes of each combination

    long long max = 0;


    // 1. Choose a route as the first one
    for (long long i = 0; i < routes.size(); i++) {

        if (DEBUG) cout << "i=" << i << "\n";
        vector<long long> combination;
        combination.push_back(i);

        // 2. Add another new route, one by one
        for (long long j = i + 1; j < routes.size(); j++) {
            // 3. Examine if the new route is valid
                // Define is_valid() // DONE
                // Compare the new route with the previous route
            long long previous_r = combination[combination.size() - 1];
            if (is_valid(routes[previous_r], routes[j])) {
                combination.push_back(j);
            }
        }

        // Check comination
        if (DEBUG) {
            for (long long i = 0; i < combination.size(); i++) {
                print_r(routes[combination[i]]);
            }
            cout << "size = " << combination.size() << "\n\n";
        }

        max = (combination.size() > max) ? combination.size() : max;
    }

    // GO BACKWARDS

    // 1. Choose a route as the first one
    // GO BACKWARDS
    for (long long i = routes.size() - 1; i >= 0; i--) {

        if (DEBUG) cout << "i=" << i << "\n";
        vector<long long> combination;
        combination.push_back(i);

        // 2. Add another new route, one by one
        // GO BACKWARDS
        for (long long j = i - 1; j >= 0; j--) {
            // 3. Examine if the new route is valid
                // Define is_valid() // DONE
                // Compare the new route with the previous route
            long long previous_r = combination[combination.size() - 1];

            // GO BACKWARDS
            if (is_valid(routes[j], routes[previous_r])) {
                combination.push_back(j);
            }
        }

        // Check comination
        if (DEBUG) {
            for (long long i = 0; i < combination.size(); i++) {
                print_r(routes[combination[i]]);
            }
            cout << "size = " << combination.size() << "\n\n";
        }

        max = (combination.size() > max) ? combination.size() : max;
    }

    // 4. Find the max count
    cout << max << "\n";


}