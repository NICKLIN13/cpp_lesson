#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

bool DEBUG = false;
const long long R_MAX = 100001; // HOTFIX
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

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

    // 
    array<long long, R_MAX> dp;
    fill(dp.begin(), dp.end(), 1);
    for (long long i = 0; i < R; i++) {
        if (DEBUG) cout << "i=" << i << "\n";

        for (long long j = 0; j < i; j++) {
            if (is_valid(routes[j], routes[i]) && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // 4. Find the max count
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}