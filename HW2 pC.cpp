#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

bool DEBUG = false;
const long long R_MAX = 10000;

void print_r(array<long long, 2> r) {
    cout << r[0] << "," << r[1] << "\n";
}

void print_routes(array<array<long long, 2>, R_MAX>& routes, long long R) {
    for (long long i = 0; i < R; i++) {
        for (long long j = 0; j < 2; j++) {
            cout << routes[i][j] << " ";
        }
        cout << "\n";
    }
}

bool is_valid(array<long long, 2> p, array<long long, 2> q) {
    // p_start < q_start AND p_end < q_end
    return (p[1] < q[1] && p[0] < q[0]);
}

int main() {
    // DEBUG = true;
    long long N = 0, M = 0, R = 0;
    cin >> N >> M;
    cin >> R;

    // Read inputs
    array<array<long long, 2>, R_MAX> routes{};
    for (long long i = 0; i < R; i++) {
        cin >> routes[i][0] >> routes[i][1];
    }

    // Confirm inputs
    if (DEBUG) {
        cout << "\n";
        cout << "N=" << N << ", M=" << M << "\n";
        print_routes(routes, R);
    }

    // Sort routes
    sort(routes.begin(), routes.begin()+R);
    if (DEBUG) print_routes(routes, R);

    // Count the valid routes of each combination

    long long max = 1;


    // 1. Choose a route as the first one
    for (long long i = 0; i < R; i++) {
        if (DEBUG) cout << "i=" << i << "\n";
        array<long long, R_MAX> combination{};
        long long combination_size = 0;
        combination[combination_size++] = i;

        // 2. Add another new route, one by one
        for (long long j = i + 1; j < R; j++) {
            // 3. Examine if the new route is valid
                // Define is_valid() // DONE
                // Compare the new route with the previous route
            long long previous_r = combination[combination_size - 1];
            if (is_valid(routes[previous_r], routes[j])) {
                combination[combination_size++] = j;
            }
        }

        // Check combination
        if (DEBUG) {
            for (long long k = 0; k < combination_size; k++) {
                print_r(routes[combination[k]]);
            }
            cout << "size = " << combination_size << "\n\n";
        }

        max = (combination_size > max) ? combination_size : max;
    }

    // GO BACKWARDS

    // 1. Choose a route as the first one
    // GO BACKWARDS
    for (long long i = R - 1; i >= 0; i--) {
        if (DEBUG) cout << "i=" << i << "\n";
        array<long long, R_MAX> combination{};
        long long combination_size = 0;
        combination[combination_size++] = i;

        // 2. Add another new route, one by one
        // GO BACKWARDS
        for (long long j = i - 1; j >= 0; j--) {
            // 3. Examine if the new route is valid
                // Define is_valid()
                // Compare the new route with the previous route
            long long previous_r = combination[combination_size - 1];
            // GO BACKWARDS
            if (is_valid(routes[j], routes[previous_r])) {
                combination[combination_size++] = j;
            }
        }

        // Check combination
        if (DEBUG) {
            for (long long k = 0; k < combination_size; k++) {
                print_r(routes[combination[k]]);
            }
            cout << "size = " << combination_size << "\n\n";
        }

        max = (combination_size > max) ? combination_size : max;
    }

    // 4. Find the max count
    cout << max << "\n";


}