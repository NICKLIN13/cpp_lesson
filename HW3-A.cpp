#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<long long>> adj;
vector<pair<long long, long long>> ans;
vector<long long> visited, low;
long long timer = 1; // Should be bigger than 0 (default value of visited)

void dfs(long long curr_id, long long prev_id) {
    visited[curr_id] = low[curr_id] = timer++; // Set current timer
    for (auto next_id : adj[curr_id]) { // Visit all adj nodes

        if (visited[next_id] == 0) { // If next_id is NOT visited yet
            dfs(next_id, curr_id); // Go deeper
            low[curr_id] = min(low[curr_id], low[next_id]); // Back-tracking: Update low of curr_id

            // After next_id is checked
            if (low[next_id] > visited[curr_id]) { // If next_id is not in a loop
                auto a = min(curr_id, next_id);
                auto b = max(curr_id, next_id);
                ans.push_back({a, b}); // A bridge is found. Add it to the ans
            }

        } else if (next_id != prev_id) { // If next_id IS visited AND next_id is NOT prev_id
            // Do NOT go deeper
            low[curr_id] = min(low[curr_id], visited[next_id]); // A loop is found. Update low of curr_id
        }
        // else: next_id == prev_id
        // => U-turned. Do nothing
    }
    

}

int main(){
    long long N, M, u, v;
    cin >> N >> M;

    adj = vector<vector<long long>>(N);
    visited = vector<long long>(N);
    low = vector<long long>(N);

    // Read edges
    for(long long i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    if(ans.empty()){
        cout << "No Critical Road\n";
    } else {
        sort(ans.begin(), ans.end());
        for(auto edge: ans) {
            cout << edge.first << " " << edge.second << "\n";
        }
    }

    for(long long i = 0; i < N; i++) {
        cout << i << " " << visited[i] << " " << low[i] << "\n";
    }
    return 0;
}

/*

6 7
0 1
1 4
0 4
2 5
2 3
3 5
0 5

*/