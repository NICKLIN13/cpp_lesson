#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<int> get_path(int start, int end, const vector<int>& parent) {
    vector<int> path;
    for(int i = end; i != start; i = parent[i]) {
        path.push_back(i);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    bool debug = true;
    debug = false;
    int MAX = numeric_limits<int>::max();
    // if (debug) MAX = 999;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    
    vector<vector<pii>> adj(N*2);
    vector<int> dist(N*2, MAX);
    vector<int> parent(N*2, -1);
    vector<bool> visited(N*2, false);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        // map_1
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        // map_2
        int u2 = u+N, v2 = v+N;
        adj[u2].push_back({v2, w});
        adj[v2].push_back({u2, w});

        // voucher = map_1 to map_2 for free (one directional)
        adj[u].push_back({v2, 0});
        adj[v].push_back({u2, 0});

    }

    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {

        if (debug) {
            for (int i = 0; i < dist.size(); i++)
            {
                cout 
                     << parent[i] << " ->\t"
                     << i << " "
                     << dist[i] << "\n";
            }
            cout << "------\n";
            
        }

        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto e : adj[u]) {
            int v = e.first;
            int next_w = e.second;
            if (debug) {
                cout << u << "->\t" 
                     << v << " " 
                     << next_w << "\n";

            }
            if (dist[v] > d + next_w) {
                dist[v] = d + next_w;
                parent[v] = u;
                pq.push({dist[v], v});
            } else if (dist[v] == d + next_w) { // Find path with more nodes
                int len_old = get_path(0, v, parent).size();
                int len_new = get_path(0, u, parent).size() + 1;
                if (len_new > len_old) {
                    parent[v] = u;
                }
            }
        }

    }

    if (debug) {
        for (int i = 0; i < dist.size(); i++)
        {
            cout << "[" << i << "]" << dist[i] << " ";
        }
        cout << "\n";
    }


    auto path = get_path(0, N*2-1, parent);

    if (debug) {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
    }

    cout << dist[dist.size() - 1] << " " 
         << path.size() - 2 << "\n";
    return 0;
}
