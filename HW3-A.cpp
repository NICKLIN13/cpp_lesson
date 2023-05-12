#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<long long>> adj;
vector<pair<long long, long long>> ans;
vector<long long> visited, low;
long long timer = 1; // Should be bigger than 0 (default value of visited)

void dfs(long long curr, long long prev) {
    visited[curr] = low[curr] = timer++; // Set current timer
    for (auto next : adj[curr]) { // Visit all adj nodes)

        if (visited[next] == 0) { // If next is NOT visited yet
            dfs(next, curr); // Go deeper
            low[curr] = min(low[curr], low[next]); // Update low
        } else if (next != prev) { // If next IS visited AND next is NOT prev
            // Do NOT go deeper
            low[curr] = min(low[curr], visited[next]); // A loop is found. Update low

            // Initial condition: curr == 0, prev == -1 
            // => low[curr] = visited[next] = 0
        }

        // After next is checked
        if (low[next] > visited[curr]) { // If next is not in a loop
            auto a = min(curr, next);
            auto b = max(curr, next);
            ans.push_back({a, b}); // A bridge is found. Add it to the ans
        }
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
    return 0;
}