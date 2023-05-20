// [Minimum Spanning Tree：Prim's Algorithm](http://alrightchiu.github.io/SecondRound/minimum-spanning-treeprims-algorithm.html)

#include <iostream>
#include <vector>
#include <iomanip>      // for setw()

const int Max_Weight = -1000;    // 初始化key[]時需要infinity, 以Max_Weight代替

class GraphMST{
private:
    int num_vertex;
    std::vector<std::vector<int>> AdjMatrix;
public:
    GraphMST():num_vertex(0){};
    GraphMST(int n):num_vertex(n){
        AdjMatrix.resize(num_vertex);
        for (int i = 0; i < num_vertex; i++) {
            AdjMatrix[i].resize(num_vertex);
        }
    }
    void AddEdge(int from, int to, int weight);

    void PrimMST(int Start = 0);        // 可以指定起點Start, 若沒有指定, 則從vertex(0)作為MST的root
    friend int MinKeyExtract(int *key, bool *visited, int size);
};

int MinKeyExtract(int *key, bool *visited, int size){

    int min = Max_Weight, min_idx = 0;
    for (int i = 0; i < size; i++) {
        if (visited[i]==false && key[i] > min) { // MAX
            min = key[i];
            min_idx = i;
        }
    }
    return min_idx;
}
void GraphMST::PrimMST(int Start){

    int key[num_vertex], predecessor[num_vertex];
    bool visited[num_vertex];

    for (int i = 0; i < num_vertex; i++) {
        key[i] = Max_Weight;
        predecessor[i] = -1;
        visited[i] = false;     // false表示vertex還沒有被visited
    }

    key[Start] = 0;
    for (int i = 0; i < num_vertex; i++) {
        int u = MinKeyExtract(key, visited, num_vertex);
        visited[u] = true;
        for (int i = 0; i < num_vertex; i++) {
            if ( visited[i]==false && AdjMatrix[u][i]!=0 && AdjMatrix[u][i] > key[i]) { // MAX
                predecessor[i] = u;
                key[i] = AdjMatrix[u][i];
            }
        }
    }

    // // print MST, 與MST演算法主體無關
    // std::cout << std::setw(3) << "v1" << " - " << std::setw(3) << "v2"<< " : weight\n";
    // int i = (Start+1)%num_vertex;   // 若從4開始, i依序為5,6,0,1,2,3
    // while (i != Start) {
    //     std::cout << std::setw(3) << predecessor[i]+1 << " - " << std::setw(3) << i+1
    //               << " : " << std::setw(4) << AdjMatrix[predecessor[i]][i] <<"\n";
    //     i = (++i)%num_vertex;       // 到了6之後, 6+1 = 7, error:bad_access, 透過mod把7喬回0
    // }


    long long sum = 0;
    for (int i = 0; i < num_vertex; i++) {
        if (key[i] != Max_Weight) sum += key[i];
    }
    std::cout << sum << "\n";
}
void GraphMST::AddEdge(int from, int to, int weight){
    AdjMatrix[from][to] = weight;
}

int main(){

    // GraphMST g6(7);
    // g6.AddEdge(0, 1, 5);g6.AddEdge(0, 5, 3);
    // g6.AddEdge(1, 0, 5);g6.AddEdge(1, 2, 10);g6.AddEdge(1, 4, 1);g6.AddEdge(1, 6, 4);
    // g6.AddEdge(2, 1, 10);g6.AddEdge(2, 3, 5);g6.AddEdge(2, 6, 8);
    // g6.AddEdge(3, 2, 5);g6.AddEdge(3, 4, 7);g6.AddEdge(3, 6, 9);
    // g6.AddEdge(4, 1, 1);g6.AddEdge(4, 3, 7);g6.AddEdge(4, 5, 6);g6.AddEdge(4, 6, 2);
    // g6.AddEdge(5, 0, 3);g6.AddEdge(5, 4, 6);
    // g6.AddEdge(6, 1, 4);g6.AddEdge(6, 2, 8);g6.AddEdge(6, 3, 9);g6.AddEdge(6, 4, 2);

    // std::cout << "MST found by Prim:\n";
    // g6.PrimMST(2);

    long long N, M, u, v, w;
    std::cin >> N >> M;
    GraphMST g = (N);
    for (long long i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        g.AddEdge(u-1, v-1, w);
        g.AddEdge(v-1, u-1, w);
    }
    g.PrimMST(0);

    // If there is still more than one way to meet the above two points, the total energy consumption of the network should be minimized. In other words, the sum of bandwidths of the remaining cables should be minimized.

    return 0;
}

/*
10 9
1 2 5
2 7 7
7 10 11
6 10 6
2 8 9
7 9 8
5 7 4
4 5 2
3 5 3
*/