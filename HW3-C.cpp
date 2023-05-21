// [Flood fill Algorithm - how to implement fill() in paint? - GeeksforGeeks](https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/)
// A C++ program to implement flood fill algorithm
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>

#define ll long long

using namespace std;

bool debug = true;

map<char, char> mp { {'O', '='}, {'C', '.'}, {'L', 'L'}, {'B', 'B'}, {'D', 'D'},
};

struct Block {
    ll x;
    ll y;
    char type;
    ll timer;
};

struct Position {
    ll x, y;
};

// [Union-Find / Disjoint-Set – 陪你刷題 – haogroot's Blog](https://haogroot.com/2021/01/29/union_find-leetcode/)
class UnionFind {
    public:
    UnionFind(ll N, ll M) {
        count = 0;
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < M; j++) {
                parent.push_back(i*M + j);
                count++;
                rank.push_back(0);
            }
        }
    }

    ll find(ll i) { // path compression
        if (i != parent[i]) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void Union(ll x, ll y) { // union with rank
        ll root_x = find (x);
        ll root_y = find (y);
        if (root_x != root_y) {
            if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
            } else if (rank[root_y] > rank[root_x]) {
                parent[root_x] = root_y;
            } else {
                parent[root_y] = root_x;
                rank[root_x] +=1;
            }
            count--;
        }
    }

    ll getCount() const {
        return count;
    }

    private:
    vector<ll> parent;
    vector<ll> rank;
    ll count; // # of connected components
};

class Lava {
private:
    const ll N, M;
    vector<vector<Block>> room;
    queue<Position> q;
    UnionFind uf;
public:
    ll timer_ = 0;
    Lava(ll N, ll M): N(N), M(M), uf(N, M) {
        room.resize(N+2);
        for (ll i = 0; i < N+2; i++) {
            room[i].resize(M+2);
        }
    }

    bool IsQEmpty() {
        ll x = q.front().x, y = q.front().y;
        auto curr = GetBlock(x, y);
        return (curr.timer > timer_);
    }

    bool IsValidPosition(ll x, ll y) {
        return (x >= 0 && x < N && y >= 0 && y < M);
    }

    Block GetBlock(ll x, ll y) {
        return room[x+1][y+1];
    }

    void SetBlock(ll x, ll y, char type, ll timer) {
        if (!IsValidPosition(x, y)) return;
        room[x+1][y+1] = Block{x, y, type, timer};
    }

    void SetBorder(ll x, ll y) {
        room[x+1][y+1] = Block{x, y, 'O', 0};
    }

    void PrintRoom() {
        for (auto row: room) {
            for (auto col: row) {
                cout << mp[col.type];
            }
            cout << "\n";
        }
    }

    void SetLava(ll x, ll y) {
        if (!IsValidPosition(x, y)) return;
        if (GetBlock(x, y).type != 'C') return;
        if (GetBlock(x, y).type == 'L') return;
        SetBlock(x, y, 'L', timer_ + 1);
        PrintRoom();
        q.push({x, y});
    }

    void SpreadLava(ll x, ll y) {
        SetLava(x-1, y);
        SetLava(x+1, y);
        SetLava(x, y-1);
        SetLava(x, y+1);
    }

    void UnionLava(ll x1, ll y1, ll x2, ll y2) {
        uf.Union(
            xy2uf(x1, y1),
            xy2uf(x2, y2)
        );
    }

    ll xy2uf(ll x, ll y) {
        return (x+1) * N + (y+1);
    }

    void Run() {
        while (!q.empty()) {
            if (debug) cout << "q:" << q.size() << "\n";
            // use debugger when using c++ -O2 optmiser might break this
            ll x = q.front().x, y = q.front().y;
            auto curr = GetBlock(x, y);

            if (debug) cout << curr.x << " " << curr.y << " "  << curr.type << " " << curr.timer << "\n";
            if (debug) cout << "timer_:" << timer_ << "\n";
            if (curr.timer > timer_) break;
            q.pop();

            SpreadLava(curr.x, curr.y);
        }
    }
};

// Driver code
int main()
{
    // debug = false;
    stringstream cin("3 4\nCCCD\nCCCC\nBCLC");

    ll N, M;
    cin >> N >> M;
    Lava l(N, M);

    // Initialization
    for (ll i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (ll j = 0; j < M; j++) {
            auto type = row[j];
            if (type == 'L') {
                l.SetBlock(i, j, 'C', 0); // Lava must set on 'C'
                l.SetLava(i, j);
            } else {
                l.SetBlock(i, j, type, 0);
            }
        }
    }

    for (ll i = -1; i <= N; i++) {
        l.SetBorder(i, -1);
        l.SetBorder(i, M);
    }
    for (ll j = -1; j <= M; j++) {
        l.SetBorder(-1, j);
        l.SetBorder(N, j);
    }

    if (debug) {
        l.PrintRoom();
        cout << "\n";
    }

    while (true) {
        l.timer_++;
        l.Run();
        if (l.IsQEmpty()) break;
    }

    if (debug) {
        l.PrintRoom();
        cout << "\n";
    }

}