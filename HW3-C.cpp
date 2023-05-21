// [Flood fill Algorithm - how to implement fill() in paint? - GeeksforGeeks](https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/)
// A C++ program to implement flood fill algorithm
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool debug = true;

class Lava {
private:
    const int N, M;
    vector<vector<char>> room;
    void floodFillUtil(int x, int y, char prevC, char newC);
public:
    Lava(int N, int M): N(N), M(M) {
        room.resize(N);
        for (int i = 0; i < N; i++) {
            room[i].resize(M);
        }
    }
    void SetRoom(int x, int y, char C);
    void PrintRoom();
    void floodFill(int x, int y, char newC);

};

void Lava::SetRoom(int x, int y, char c) {
    if (debug) cout << x << "," << y << " = " << c << "\n";
    room[x][y] = c;
    if (debug) cout << "done\n";

}

void Lava::PrintRoom() {
    for (auto row: room) {
        for (auto col: row) {
            cout << col;
        }
        cout << "\n";
    }
}

// A recursive function to replace previous color 'prevC' at  '(x, y)'
// and all surrounding pixels of (x, y) with new color 'newC' and
void Lava::floodFillUtil(int x, int y, char prevC, char newC)
{
    // Base cases
    if (x < 0 || x >= N || y < 0 || y >= M)
        return;
    if (room[x][y] != prevC)
        return;
    if (room[x][y] == newC)
        return;

    // Replace the color at (x, y)
    SetRoom(x, y, newC);

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
    char prevC = room[x][y];
    if (prevC == newC) return;
    floodFillUtil(x, y, prevC, newC);
}

// Driver code
int main()
{
    debug = false;
    int N, M;
    cin >> N >> M;
    Lava l(N, M);

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            l.SetRoom(i, j, row[j]);
        }
    }
    l.floodFill(0, 0, 'A');
    l.PrintRoom();

}