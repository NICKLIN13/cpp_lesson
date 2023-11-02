#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<vector<int>> floydWarshall(int n, vector<vector<int>> adj) {
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = adj[i][j];
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

int main() {
    bool debug = true;
    debug = false;
    int N, M, K;
    cin >> N >> M >> K;

    unordered_map<string, int> townMap;
    vector<vector<int>> adj(N, vector<int>(N, INF));

    for(int i = 0; i < M; i++) {
        string u, v;
        int d;
        cin >> u >> v >> d;
        if(!townMap.count(u)) townMap[u] = townMap.size();
        if(!townMap.count(v)) townMap[v] = townMap.size();

        if(d < adj[townMap[u]][townMap[v]]) {
            adj[townMap[u]][townMap[v]] = d;
            adj[townMap[v]][townMap[u]] = d;
        }

        if(debug) {
            cout << u << "\t" << townMap[u] << "\n";
            cout << v << "\t" << townMap[v] << "\n";
        }
    }

    vector<int> path(K);
    for(int i = 0; i < K; i++) {
        string s;
        cin >> s;
        path[i] = townMap[s];
    }

    vector<vector<int>> dist = floydWarshall(N, adj);

    int totalDistance = 0;
    for(int i = 0; i < K - 1; i++) {
        totalDistance += dist[path[i]][path[i + 1]];
    }

    cout << totalDistance << endl;

    return 0;
}
