#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
// #define debug true

using namespace std;

const int INF = numeric_limits<int>::max();

class Solution {
public:

    int n, size;
    int source, sink;

    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> res;
    vector<int> parent;

    vector<int> a, b;
    vector<vector<int>> x;

    Solution(int n)
        : n(n){
        source = 0;
        sink = n+1;
        size = n+2; // n + source + sink

        adj = vector<vector<pair<int, int>>>(size);
        res = vector<vector<int>>(size, vector<int>(size));
        parent = vector<int>(size);
        a = vector<int>(size);
        b = vector<int>(size);
        x = vector<vector<int>>(size, vector<int>(size));

    }


    void add_edge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, 0});
        res[u][v] += w;
        res[v][u] += 0;
    }

    bool bfs() {
        #if defined(debug)
        cout << "bfs" << "\n";
        #endif // debug
        
        
        // parent = vector<int>(size, -1);
        fill(parent.begin(), parent.end(), -1);
        parent[source] = source;
        queue<pair<int, int>> q;
        q.push({source, INF});

        while (!q.empty()) {
            int u = q.front().first, flow = q.front().second;
            q.pop();

            for (auto& e : adj[u]) {
                int v = e.first, w = e.second;

                #if defined(debug)
                cout
                    << u << " "
                    << v << " "
                    << w << " "
                    << parent[v] << " "
                    << res[u][v] << " "
                    << "\n";
                #endif // debug

                if (parent[v] == -1 && res[u][v] > 0) {
                    parent[v] = u;
                    int new_flow = min(flow, res[u][v]);
                    if (v == sink)
                        return new_flow;
                    q.push({v, new_flow});

                    #if defined(debug)
                    cout
                        << "{" << ""
                        << v << ""
                        << "," << ""
                        << new_flow << ""
                        << "}" << ""
                        << "\n";
                    #endif // debug

                }
            }
        }

        return 0; // Sink is not reached
    }

    int maxflow() {
        int maxflow = 0, new_flow = 0;

        new_flow = bfs();
        
        #if defined(debug)
        cout
            << new_flow << " "
            << "\n";
        #endif // debug

        while (new_flow) {
            maxflow += new_flow;
            int cur = sink;
            while (cur != source) {
                int prev = parent[cur];
                res[prev][cur] -= new_flow;
                res[cur][prev] += new_flow;
                cur = prev;
            }
            new_flow = bfs();

            #if defined(debug)
            cout << new_flow << "\n";
            #endif // debug
            
        }

        #if defined(debug)
        cout
            << "maxflow" << " = "
            << maxflow << " "
            << "\n";
        #endif // debug
        return maxflow;
    }

    void main() {

        int total_a = 0, total_b = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            total_a += a[i];
            add_edge(source, i, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            total_b += b[i];
            add_edge(i, sink, b[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> x[i][j];
                if (i != j)
                    add_edge(i, j, x[i][j]);
            }
        }

        int max_flow = maxflow();
        cout << total_b - max_flow<< '\n';
    }

};


int main() {
    int n;
    cin >> n;
    Solution s(n);
    s.main();
    return 0;
}