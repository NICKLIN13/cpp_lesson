#include <iostream>
#include <vector>
using namespace std;

#define DEBUG false

void print_r(vector<int> r) {
    cout << r[0] << "," << r[1] << "\n";
}

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
    if (DEBUG) {
        cout << "\n";
        cout << "N=" << N << ", M=" << M << "\n";
        print_routes(routes);
    }

    // Sort routes
    sort(routes.begin(), routes.end());
    if (DEBUG) print_routes(routes); // TEST

    // Count the valid routes of each combination

    int max = 0;
    // 1. Choose a route as the first one
    for (int i = 0; i < routes.size(); i++) {

        if (DEBUG) cout << "i=" << i << "\n"; // TEST
        vector<vector<int>> combination;
        combination.push_back(routes[i]);
        if (DEBUG) print_r(routes[i]); // TEST

        // 2. Add another new route, one by one
        for (int j = i + 1; j < routes.size(); j++) {
            // 3. Examine if the new route is valid
                // Define is_valid() // DONE
                // Compare the new route with the previous route
            vector<int> previous_r = combination[combination.size() - 1];
            vector<int> new_r = routes[j];
            if (is_valid(previous_r, new_r)) {
                combination.push_back(new_r);
                
                // TEST
                if (DEBUG) {
                    // cout << combination.size() << ":\n";
                    // cout << "prev = ";
                    // if (DEBUG) print_r(previous_r);
                    // if (DEBUG) print_r(new_r);
                    // cout << "\n";
                    if (DEBUG) print_routes(combination);
                }

            }
        }

        // Check comination // TEST
        if (DEBUG) {
            print_routes(combination); 
            cout << "size = " << combination.size() << "\n\n";
        }

        max = (combination.size() > max) ? combination.size() : max;
    }


    // 4. Find the max count
    cout << max << "\n";


}