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

class Lava {
private:
    const int N, M;
    vector<vector<Block> > room;
    queue<Block> q;
public:
    int timer = 0;
    Lava(int N, int M): N(N), M(M) {
        room.resize(N+2);
        for (int i = 0; i < N+2; i++) {
            room[i].resize(M+2);
        }
    }

    bool IsQEmpty() {
        return q.empty();
    }

    bool IsValidPosition(int x, int y) {
        return (x >= 0 && x < N && y >= 0 && y < M);
    }

    Block GetBlock(int x, int y) {
        return room[x+1][y+1];
    }

    void SetBlock(int x, int y, char type) {
        // if (!IsValidPosition(x, y)) return; // DOING
        room[x+1][y+1] = Block{x, y, type, timer};
        if (type == 'L') {
            SetLava(x, y);
        }
    }

    void PrintRoom() {
        for (auto row: room) {
            for (auto col: row) {
                cout << mp[col.type];
            }
            cout << "\n";
        }
    }

    // A recursive function to replace previous color 'prevC' at  '(x, y)'
    // and all surrounding pixels of (x, y) with new color 'newC' and
    void floodFillUtil(int x, int y, char prevC, char newC)
    {
        if (!IsValidPosition(x, y)) return;

        auto currC = GetBlock(x, y).type;
        if (currC != prevC) return;
        if (currC == newC) return;

        // Replace the color at (x, y)
        SetBlock(x, y, newC);

        // Recur for north, east, south and west
        floodFillUtil(x+1, y, prevC, newC);
        floodFillUtil(x-1, y, prevC, newC);
        floodFillUtil(x, y+1, prevC, newC);
        floodFillUtil(x, y-1, prevC, newC);
    }

    // It mainly finds the previous color on (x, y) and
    // calls floodFillUtil()
    void floodFill(int x, int y, char newC)
    {
        char prevC = GetBlock(x, y).type;
        if (prevC == newC) return;
        floodFillUtil(x, y, prevC, newC);
    }

    void SetLava(int x, int y) {
        if (!IsValidPosition(x, y)) return;
        if (GetBlock(x, y).type != 'C') return;
        SetBlock(x, y, 'L'); // TODO LOOP?
        q.push(GetBlock(x, y));
    }

    void SpreadLava(int x, int y) {
        SetLava(x-1, y);
        SetLava(x+1, y);
        SetLava(x, y-1);
        SetLava(x, y+1);
    }

    void Run() {
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            SpreadLava(curr.x, curr.y);
        }
        
    }
};


// Driver code
int main()
{
    debug = false;
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
            l.SetBlock(i, j, type);
        }

    }
    for (int i = -1; i <= N; i++) {
        l.SetBlock(i, -1, 'O');
        l.SetBlock(i, M, 'O');
    }
    for (int j = -1; j <= M; j++) {
        l.SetBlock(-1, j, 'O');
        l.SetBlock(N, j, 'O');
    }


    // while (true) {
    //     l.timer++;
    //     l.Run();
    //     if (l.IsQEmpty()) break;
    // }

    l.PrintRoom();

}