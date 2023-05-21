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
    void floodFillUtil(int x, int y, char prevC, char newC);
    queue<Block> q;
public:
    Lava(int N, int M): N(N), M(M) {
        room.resize(N+2);
        for (int i = 0; i < N+2; i++) {
            room[i].resize(M+2);
        }
    }
    void SetBlock(int x, int y, char type, int timer);
    Block GetBlock(int x, int y);
    bool IsValidPosition(int x, int y);
    void PrintRoom();
    void floodFill(int x, int y, char newC);
    void EnqueueLava(int x, int y);
    void SpreadLava(int x, int y, char prevC, char newC);

};

bool Lava::IsValidPosition(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

Block Lava::GetBlock(int x, int y) {
    return room[x+1][y+1];
}

void Lava::SetBlock(int x, int y, char type, int timer) {
    room[x+1][y+1] = Block{x, y, type, timer};
}

void Lava::PrintRoom() {
    for (auto row: room) {
        for (auto col: row) {
            cout << mp[col.type];
        }
        cout << "\n";
    }
}

// A recursive function to replace previous color 'prevC' at  '(x, y)'
// and all surrounding pixels of (x, y) with new color 'newC' and
void Lava::floodFillUtil(int x, int y, char prevC, char newC)
{
    if (!IsValidPosition(x, y)) return;

    auto currC = GetBlock(x, y).type;
    if (currC != prevC) return;
    if (currC == newC) return;

    // Replace the color at (x, y)
    SetBlock(x, y, newC, GetBlock(x, y).timer);

    // Recur for north, east, south and west
    floodFillUtil(x+1, y, prevC, newC);
    floodFillUtil(x-1, y, prevC, newC);
    floodFillUtil(x, y+1, prevC, newC);
    floodFillUtil(x, y-1, prevC, newC);
}

// It mainly finds the previous color on (x, y) and
// calls floodFillUtil()
void Lava::floodFill(int x, int y, char newC)
{
    char prevC = GetBlock(x, y).type;
    if (prevC == newC) return;
    floodFillUtil(x, y, prevC, newC);
}

void Lava::EnqueueLava(int x, int y) {
    q.push(room[x][y]);
}

void Lava::SpreadLava(int x, int y, char prevC, char newC)
{
    if (!IsValidPosition(x, y)) return;

    auto currC = GetBlock(x, y).type;
    if (currC != prevC) return;
    if (currC == newC) return;

    // Replace the color at (x, y)
    SetBlock(x, y, newC, GetBlock(x, y).timer);
}

// Driver code
int main()
{
    debug = false;
    stringstream cin("3 4\nCCCD\nCCCC\nBCLC");

    int N, M;
    cin >> N >> M;
    Lava l(N, M);

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            auto type = row[j];
            l.SetBlock(i, j, type, 0);
        }

    }
    for (int i = -1; i <= N; i++) {
        l.SetBlock(i, -1, 'O', 0);
        l.SetBlock(i, M, 'O', 0);
    }
    for (int j = -1; j <= M; j++) {
        l.SetBlock(-1, j, 'O', 0);
        l.SetBlock(N, j, 'O', 0);
    }


    l.PrintRoom();

}