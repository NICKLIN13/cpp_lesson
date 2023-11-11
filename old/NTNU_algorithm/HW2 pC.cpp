#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

bool DEBUG = false;
const long long R_MAX = 1000001;

bool is_valid(array<long long, 2> p, array<long long, 2> q) {
    // p_start < q_start AND p_end < q_end
    return (p[1] < q[1] && p[0] < q[0]);
}

void print_routes(vector<array<long long, 2>>& routes) {
    for (long long i = 0; i < routes.size(); i++) {
        for (long long j = 0; j < 2; j++) {
            cout << routes[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // DEBUG = true;
    long long N = 0, M = 0, R = 0;
    cin >> N >> M;
    cin >> R;

    // Read inputs
    vector<array<long long, 2>> routes(R, {0, 0});

    cout << "\n";
    print_routes(routes);
    cout << "\n";
    
    for (long long i = 0; i < R; i++) {
        cin >> routes[i][0] >> routes[i][1];
    }

    // Confirm inputs
    if (DEBUG) {
        cout << "\n";
        cout << "N=" << N << ", M=" << M << "\n";
    }

    // Sort routes
    sort(routes.begin(), routes.begin()+R);

    cout << "\n";
    print_routes(routes);
    cout << "\n";

    long long dp[R_MAX] = {1};
    for (long long i = 0; i < R; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";

    for (long long i = 0; i < R; i++) {
        if (DEBUG) cout << "i=" << i << "\n";

        for (long long j = 0; j < i; j++) {
            if (is_valid(routes[j], routes[i]) && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for (long long i = 0; i < R; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";

    // 4. Find the max count
    cout << *max_element(dp, dp+R) << "\n";
}