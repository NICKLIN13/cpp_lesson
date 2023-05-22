// [Flood fill Algorithm - how to implement fill() in paint? - GeeksforGeeks](https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/)
// A C++ program to implement flood fill algorithm
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define ll long long

using namespace std;

bool debug = true;

map<char, char> mp { {'O', '='}, {'C', '.'}, {'L', 'L'}, {'B', 'B'}, {'D', 'D'},
};

#define DIRECTIONS 4
int dx[DIRECTIONS] = {0, 0, -1, 1};
int dy[DIRECTIONS] = {1, -1, 0, 0};

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
    ll N, M;
    UnionFind(ll N, ll M): N(N), M(M) {
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

    void print() {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < M; j++) {
                cout << parent[i*M + j];
            }
            cout << "\n";
        }
        cout << "\n";
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
    Block B, D;
    ll timer_ = 0;
    Lava(ll N, ll M)
    : N(N)
    , M(M)
    , uf(N, M) 
    {
        room.resize(N);
        for (ll i = 0; i < N; i++) {
            room[i].resize(M);
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
        return room[x][y];
    }

    void SetBlock(ll x, ll y, char type, ll timer) {
        if (!IsValidPosition(x, y)) return;
        room[x][y] = Block{x, y, type, timer};
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
        // if (debug) PrintRoom();
        q.push({x, y});
    }

    void SpreadLava(ll x, ll y) {
        for (ll i = 0; i < DIRECTIONS; i++) {
            ll nx = x+dx[i], ny = y+dy[i];
            SetLava(nx, ny);
        }
    }

    ll xy2uf(ll x, ll y) {
        return x*M + y;
    }

    void UnionRoad(UnionFind &temp, ll x1, ll y1, ll x2, ll y2) {
        if (!IsValidPosition(x2, y2)) return;
        char type = GetBlock(x2, y2).type;
        if (type == 'C' || type == 'B' || type == 'D') {
            temp.Union(
                xy2uf(x1, y1),
                xy2uf(x2, y2)
            );
        }
    }

    bool IsConnected(UnionFind &temp, ll x1, ll y1, ll x2, ll y2) {
        return (temp.find(xy2uf(x1, y1)) == temp.find(xy2uf(x2, y2)));
    }

    void Run() {
        while (!q.empty()) {
            // if (debug) cout << "q:" << q.size() << "\n";
            // use debugger when using c++ -O2 optmiser might break this
            ll x = q.front().x, y = q.front().y;
            auto curr = GetBlock(x, y);

            // if (debug) cout << curr.x << " " << curr.y << " "  << curr.type << " " << curr.timer << "\n";
            // if (debug) cout << "timer_:" << timer_ << "\n";
            if (curr.timer > timer_) break;
            q.pop();

            SpreadLava(curr.x, curr.y);
        }
    }

    bool UfEscape() { // DOING
        // TODO Duplicate a uf?
        UnionFind temp(uf);
        ll Bx, By, Dx, Dy;
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < M; j++) {
                auto cell = GetBlock(i, j);
                char type = cell.type;
                if (type == 'C' || type == 'B' || type == 'D') {
                    ll x = cell.x, y = cell.y;
                    if (type == 'B') {Bx = x; By = y;}
                    if (type == 'D') {Dx = x; Dy = y;}

                    for (ll k = 0; k < DIRECTIONS; k++) {
                        ll nx = x+dx[k], ny = y+dy[k];
                        UnionRoad(temp, x, y, nx, ny);
                    }
                }
            }
        }
        if (debug) temp.print();
        return IsConnected(temp, Bx, By, Dx, Dy);
    }
    
    /*
    bool BfsEscape(){
        queue<Block> Q;
        bool v[N][M]; // visited
        ll d[N][M]; // distance
        memset(v, 0, sizeof(v));
        memset(d, 0, sizeof(d));
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        Q.push(B);
        v[B.x][B.y] = true;
        while (!Q.empty()){
            auto cell = Q.front();
            Q.pop();
            if (debug) {
                for (ll i = 0; i < N; i++) {
                    for (ll j = 0; j < M; j++) {
                        cout << d[i][j];
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
            if (debug) cout << "cell: (" << cell.x << "," << cell.y << ")\n";
            for (int i=0; i < DIRECTIONS; ++i){
                int nx = cell.x + dx[i], ny = cell.y + dy[i];
                if (
                    IsValidPosition(nx, ny) 
                    && !v[nx][ny] 
                    && (GetBlock(nx, ny).type == 'C'
                        || GetBlock(nx, ny).type == 'D')
                    // && d[cell.x][cell.y] + 1 < d[nx][ny]
                    ) {
                    if (debug) cout << "(" << nx << "," << ny << ") ";

                    v[nx][ny] = true;
                    d[nx][ny] = d[cell.x][cell.y] + 1;
                    if(GetBlock(nx, ny).type == 'D') return true;
                    Q.push(GetBlock(nx, ny));
                }
            }
            if (debug) cout << "\n";

        }
        return false;
    }
    */
};

// Driver code
int main()
{
    debug = false;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // stringstream cin("3 4\nCCCD\nCCCC\nBCLC"); // 1
    // stringstream cin("4 4\nCCCL\nCCCC\nCCCC\nBCDC"); // 4
    // stringstream cin("2 4\nCCCD\nBCLC"); // -1
    // stringstream cin("4 5\nCCCCC\nCCCOC\nCCCOC\nBCCDL"); // 7
    // stringstream cin("4 5\nCCCCC\nCCCOC\nCCCOC\nBCCDL"); // 7
    // stringstream cin("10 10\nCCCCCCCCCD\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCBCCCCCCLC"); // 8
    // stringstream cin("10 10\nLCCCCCCCCD\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCLCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCCCCCCCCCC\nCBCCCCCCLC"); // 3
    // stringstream cin("8 8\nLCCCCCCD\nCCCCCCCC\nCCCCCCCC\nCCCCCCCC\nCCCCCCCC\nCCCCCCCC\nCCCCCCCC\nCBCCCCLC"); // 5
    // stringstream cin("6 4\nBCCL\nCCCL\nCDOL\nCCCC\nCOLC\nCLCL"); // 2


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
                l.SetBlock(i, j, 'C', 0); // Lava must be set on 'C'
                l.SetLava(i, j);
            } else {
                l.SetBlock(i, j, type, 0);
                if (type == 'B') l.B = l.GetBlock(i, j);
                if (type == 'D') l.D = l.GetBlock(i, j);
            }
        }
    }

    // for (ll i = -1; i <= N; i++) {
    //     l.SetBorder(i, -1);
    //     l.SetBorder(i, M);
    // }
    // for (ll j = -1; j <= M; j++) {
    //     l.SetBorder(-1, j);
    //     l.SetBorder(N, j);
    // }

    if (debug) {
        l.PrintRoom();
        cout << "\n";
    }

    while (true) {
        l.timer_++;
        l.Run();
        if (l.IsQEmpty()) {
            if (debug) cout << l.timer_ << "\n";
            if (debug) l.PrintRoom();
            if (debug) cout << "~~~~~~~~~~~~\n";
            if (!l.UfEscape()) {
                l.timer_--;
                break;
            }
        }
    }

    if (l.timer_ == 0) {
        cout << -1 << "\n";
        return 0;
    }

    cout << l.timer_ << "\n";
    return 0;
}
