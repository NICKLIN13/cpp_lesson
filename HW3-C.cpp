// [Flood fill Algorithm - how to implement fill() in paint? - GeeksforGeeks](https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/)
// A C++ program to implement flood fill algorithm
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>

using namespace std;

bool debug = true;

map<char, char> mp {
    {'O', '='},
    {'C', '.'},
    {'L', 'L'},
    {'B', 'B'},
    {'D', 'D'},
};

struct Block {
    int x;
    int y;
    char type;
    int timer;
};

struct Position {
    int x, y;
};

class Lava {
private:
    const int N, M;
    vector<vector<Block> > room;
    queue<Position> q;
public:
    int timer_ = 0;
    Lava(int N, int M): N(N), M(M) {
        room.resize(N+2);
        for (int i = 0; i < N+2; i++) {
            room[i].resize(M+2);
        }
    }

    bool IsQEmpty() {
        int x = q.front().x, y = q.front().y;
        auto curr = GetBlock(x, y);
        return (curr.timer > timer_);
    }

    bool IsValidPosition(int x, int y) {
        return (x >= 0 && x < N && y >= 0 && y < M);
    }

    Block GetBlock(int x, int y) {
        return room[x+1][y+1];
    }

    void SetBlock(int x, int y, char type, int timer) {
        if (!IsValidPosition(x, y)) return;
        room[x+1][y+1] = Block{x, y, type, timer};
    }

    void SetBorder(int x, int y) {
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

    void SetLava(int x, int y) {
        if (!IsValidPosition(x, y)) return;
        if (GetBlock(x, y).type != 'C') return;
        if (GetBlock(x, y).type == 'L') return;
        SetBlock(x, y, 'L', timer_ + 1);
        PrintRoom();
        q.push({x, y});
    }

    void SpreadLava(int x, int y) {
        SetLava(x-1, y);
        SetLava(x+1, y);
        SetLava(x, y-1);
        SetLava(x, y+1);
    }

    void Run() {
        while (!q.empty()) {
            if (debug) cout << "q:" << q.size() << "\n";
            // HOTFIX use debugger when using c++ -O2 optmiser might break this
            int x = q.front().x, y = q.front().y;
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

    int N, M;
    cin >> N >> M;
    Lava l(N, M);

    // Initialization
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            auto type = row[j];
            if (type == 'L') {
                l.SetBlock(i, j, 'C', 0); // Lava must set on 'C'
                l.SetLava(i, j);
            } else {
                l.SetBlock(i, j, type, 0);
            }
        }
    }

    for (int i = -1; i <= N; i++) {
        l.SetBorder(i, -1);
        l.SetBorder(i, M);
    }
    for (int j = -1; j <= M; j++) {
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