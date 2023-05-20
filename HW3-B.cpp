// [Minimum Spanning Tree：Prim's Algorithm](http://alrightchiu.github.io/SecondRound/minimum-spanning-treeprims-algorithm.html)

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>      // for setw()
#include <stdexcept>

bool debug = false;
const int inf = 1000; // infinity
const int neg_inf = -1000; // Negative infinity

class GraphMinMaxST{
private:
    bool is_minimum = true; // If true, form MIN ST; if false, form MAX ST
    int sum = 0; // Sum of all weights in MST
    int num_vertex;
    std::vector<std::vector<int>> AdjMatrix;
public:
    GraphMinMaxST(bool is_min):num_vertex(0){
        is_minimum = is_min;
    };
    GraphMinMaxST(int n, std::string min_or_max):num_vertex(n){
        if (min_or_max == "min") is_minimum = true;
        else if (min_or_max == "max") is_minimum = false;
        else throw std::invalid_argument( "Please input \"min\" or \"max\"." );

        AdjMatrix.resize(num_vertex);
        for (int i = 0; i < num_vertex; i++) {
            AdjMatrix[i].resize(num_vertex);
        }
    }
    void AddEdge(int from, int to, int weight);
    void PrintSum();
    void PrimMST(int Start = 0);        // 可以指定起點Start, 若沒有指定, 則從vertex(0)作為MST的root
    friend int MinOrMaxKeyExtract(int *key, bool *visited, int size, bool is_min);
};

int MinOrMaxKeyExtract(int *key, bool *visited, int size, bool is_min){

    int min_or_max = (is_min) ? inf : neg_inf;
    int index = 0;

    for (int i = 0; i < size; i++) {
        bool criteria = (is_min) ? (key[i] < min_or_max) : (key[i] > min_or_max);

        if (visited[i]==false && criteria) {
            min_or_max = key[i];
            index = i;
        }
    }
    return index;
}
void GraphMinMaxST::PrimMST(int Start){

    int key[num_vertex], predecessor[num_vertex];
    bool visited[num_vertex];

    for (int i = 0; i < num_vertex; i++) {
        key[i] = (is_minimum) ? inf : neg_inf;
        predecessor[i] = -1;
        visited[i] = false;     // false表示vertex還沒有被visited
    }

    key[Start] = 0;
    for (int i = 0; i < num_vertex; i++) {
        int u = MinOrMaxKeyExtract(key, visited, num_vertex, is_minimum);
        visited[u] = true;
        for (int i = 0; i < num_vertex; i++) {
            bool criteria = (is_minimum) ? (AdjMatrix[u][i] < key[i]) : (AdjMatrix[u][i] > key[i]);
            if ( visited[i]==false && AdjMatrix[u][i]!=0 && criteria) {
                predecessor[i] = u;
                key[i] = AdjMatrix[u][i];
            }
        }
    }

    if (debug) {
        // print MST, 與MST演算法主體無關
        std::cout << std::setw(3) << "v1" << " - " << std::setw(3) << "v2"<< " : weight\n";
        int i = (Start+1)%num_vertex;   // 若從4開始, i依序為5,6,0,1,2,3
        while (i != Start) {
            std::cout << std::setw(3) << predecessor[i]+1 << " - " << std::setw(3) << i+1
                    << " : " << std::setw(4) << AdjMatrix[predecessor[i]][i] <<"\n";
            i = (++i)%num_vertex;       // 到了6之後, 6+1 = 7, error:bad_access, 透過mod把7喬回0
        }
    }

    for (int i = 0; i < num_vertex; i++) {
        int min_or_max = (is_minimum) ? inf : neg_inf;
        if (key[i] != min_or_max) sum += key[i];
    }
}

void GraphMinMaxST::PrintSum(){
    std::cout << sum << "\n";
}

void GraphMinMaxST::AddEdge(int from, int to, int weight){
    AdjMatrix[from][to] = weight;
}

int main(){

    long long N, M, u, v, w;
    std::cin >> N >> M;
    GraphMinMaxST g_max(N, "max");
    for (long long i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        g_max.AddEdge(u-1, v-1, w);
        g_max.AddEdge(v-1, u-1, w);
    }
    g_max.PrimMST(0);
    g_max.PrintSum();

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