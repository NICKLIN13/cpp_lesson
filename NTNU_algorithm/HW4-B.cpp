#include <iostream>
#include <vector>
#include <queue>
#include <utility>          // for std::pair<>
#include <iomanip>          // for std::setw()

using namespace std;

typedef pair<double, int> pdi;

vector<vector<pdi>> adj;
vector<double> prob;

void dijkstra(int start) {
    prob[start] = 1.0;
    priority_queue<pdi> pq;
    pq.push({1.0, start});

    while(!pq.empty()) {
        double p = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(p < prob[u])
            continue;

        for(auto &i : adj[u]) {
            int v = i.second;
            double pv = i.first * prob[u];

            if(pv > prob[v]) {
                prob[v] = pv;
                pq.push({prob[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    prob.resize(n, 0.0);
    for(int i = 0; i < m; i++) {
        int a, b;
        double p;
        cin >> a >> b >> p;
        adj[a].push_back({p, b});
        adj[b].push_back({p, a});
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start);
    cout << fixed << setprecision(3) << prob[end] << '\n';
    return 0;
}
