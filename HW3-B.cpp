// [Minimum Spanning Tree：Prim's Algorithm](http://alrightchiu.github.io/SecondRound/minimum-spanning-treeprims-algorithm.html)

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>      // for setw()
#include <stdexcept>

bool debug = false;
const int inf = 10000; // infinity
const int neg_inf = -inf; // Negative infinity

class GraphMinMaxST{
private:
    bool is_minimum = true; // If true, form MIN ST; if false, form MAX ST
    int sum = 0; // Sum of all weights in MST
    int bottleneck;
    const int num_vertex;
    std::vector<std::vector<int>> AdjMatrix;
public:
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

    // 可以指定起點Start, 若沒有指定, 則從vertex(0)作為MST的root; indexStart 預設從 0 開始
    void PrimMST(int Start = 0, int indexStart = 0);

    void PrintSum();
    int Bottleneck();
    int MinOrMaxKeyExtract(int *key, bool *visited);
};

int GraphMinMaxST::MinOrMaxKeyExtract(int *key, bool *visited){
    int index = 0;
    int min_key = inf, max_key = neg_inf;

    for (int i = 0; i < num_vertex; i++) {
        if (visited[i]) continue;

        if (is_minimum && key[i] < min_key) { // Find MIN
            min_key = key[i];
            index = i;
        } else if (!is_minimum && key[i] > max_key) { // Find MAX
            max_key = key[i];
            index = i;
        }
    }
    return index;
}

void GraphMinMaxST::PrimMST(int Start, int indexStart){

    int key[num_vertex], predecessor[num_vertex];
    bool visited[num_vertex];

    for (int i = 0; i < num_vertex; i++) {
        key[i] = (is_minimum) ? inf : neg_inf;
        predecessor[i] = -1;
        visited[i] = false;
    }

    key[Start] = 0;
    for (int i = 0; i < num_vertex; i++) {
        int j = MinOrMaxKeyExtract(key, visited);
        visited[j] = true;
        auto w = AdjMatrix[j][i];
        for (int i = 0; i < num_vertex; i++) {
            if (visited[i] || w == 0) continue;

            bool criteria = (is_minimum) ? (w < key[i]) : (w > key[i]);
            if (criteria) {
                predecessor[i] = j;
                key[i] = w;
            }
        }
    }

    if (debug) {
        // print MST, 與MST演算法主體無關
        std::cout << std::setw(3) << "v1" << " - " << std::setw(3) << "v2"<< " : weight\n";
        int i = (Start+1)%num_vertex;   // 若從4開始, i依序為5,6,0,1,2,3
        while (i != Start) {
            std::cout << std::setw(3) << predecessor[i]+indexStart << " - " << std::setw(3) << i+indexStart
                    << " : " << std::setw(4) << AdjMatrix[predecessor[i]][i] <<"\n";
            i = (++i)%num_vertex;       // 到了6之後, 6+1 = 7, error:bad_access, 透過mod把7喬回0
        }
    }

    int min_key = inf, max_key = neg_inf;
    for (int i = 0; i < num_vertex; i++) {
        if (key[i] == inf || key[i] == neg_inf || key[i] == 0) continue;

        sum += key[i];
        min_key = std::min(min_key, key[i]);
        max_key = std::max(max_key, key[i]);
    }

    bottleneck = (is_minimum) ? max_key : min_key;
}

void GraphMinMaxST::PrintSum(){
    std::cout << sum << "\n";
}

int GraphMinMaxST::Bottleneck(){
    return bottleneck;
}


void GraphMinMaxST::AddEdge(int from, int to, int weight){
    AdjMatrix[from][to] = weight;
}

int main(){

    long long N, M, u, v, w;
    std::cin >> N >> M;
    GraphMinMaxST g_max(N, "max");
    int indexStart = 1; // The index starts from 1
    for (long long i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        g_max.AddEdge(u-indexStart, v-indexStart, w);
        g_max.AddEdge(v-indexStart, u-indexStart, w);
    }
    g_max.PrimMST(0, indexStart);
    g_max.PrintSum();
    std::cout << g_max.Bottleneck() << "\n";

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