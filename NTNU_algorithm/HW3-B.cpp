// [Minimum Spanning Tree：Prim's Algorithm](http://alrightchiu.github.io/SecondRound/minimum-spanning-treeprims-algorithm.html)

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>      // for setw()
#include <stdexcept>
#include <limits>

bool debug = false;
const long long inf = std::numeric_limits<long long>::max();
const long long neg_inf = std::numeric_limits<long long>::min();


class GraphMinMaxST{
private:
    bool is_minimum = true; // If true, form MIN ST; if false, form MAX ST
    long long sum = 0; // Sum of all weights in MST
    long long bottleneck;
    const long long num_vertex;
    std::vector<std::vector<long long>> AdjMatrix;
public:
    GraphMinMaxST(long long n, std::string min_or_max):num_vertex(n){
        if (min_or_max == "min") is_minimum = true;
        else if (min_or_max == "max") is_minimum = false;
        else throw std::invalid_argument( "Please input \"min\" or \"max\"." );

        AdjMatrix.resize(num_vertex);
        for (long long i = 0; i < num_vertex; i++) {
            AdjMatrix[i].resize(num_vertex);
        }
    }
    void AddEdge(long long from, long long to, long long weight);

    // 可以指定起點Start, 若沒有指定, 則從vertex(0)作為MST的root; indexStart 預設從 0 開始
    void PrimMST(long long Start = 0, long long indexStart = 0);

    void PrintSum();
    long long Bottleneck();
    long long MinOrMaxKeyExtract(std::vector<long long> key, std::vector<bool> visited);
};

long long GraphMinMaxST::MinOrMaxKeyExtract(std::vector<long long> key, std::vector<bool> visited){
    long long index = 0;
    long long min_key = inf, max_key = neg_inf;

    for (long long i = 0; i < num_vertex; i++) {
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

void GraphMinMaxST::PrimMST(long long Start, long long indexStart){

    std::vector<long long> key(num_vertex, (is_minimum) ? inf : neg_inf);
    std::vector<long long> predecessor(num_vertex, -1);
    std::vector<bool> visited(num_vertex, false);

    key[Start] = 0;
    for (long long i = 0; i < num_vertex; i++) {
        long long curr = MinOrMaxKeyExtract(key, visited);
        visited[curr] = true;
        for (long long next = 0; next < num_vertex; next++) {
            auto adj = AdjMatrix[curr][next];
            if (visited[next] || adj == 0) continue;

            bool criteria = (is_minimum) ? (adj < key[next]) : (adj > key[next]);
            if (criteria) {
                predecessor[next] = curr;
                key[next] = adj;
            }
        }
    }

    if (debug) {
        // print MST, 與MST演算法主體無關
        std::cout << std::setw(3) << "v1" << " - " << std::setw(3) << "v2"<< " : weight\n";
        long long i = (Start+1)%num_vertex;   // 若從4開始, i依序為5,6,0,1,2,3
        while (i != Start) {
            std::cout << std::setw(3) << predecessor[i]+indexStart << " - " << std::setw(3) << i+indexStart
                    << " : " << std::setw(4) << AdjMatrix[predecessor[i]][i] <<"\n";
            i = (++i)%num_vertex;       // 到了6之後, 6+1 = 7, error:bad_access, 透過mod把7喬回0
        }
    }

    long long min_key = inf, max_key = neg_inf;
    for (long long i = 0; i < num_vertex; i++) {
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

long long GraphMinMaxST::Bottleneck(){
    return bottleneck;
}


void GraphMinMaxST::AddEdge(long long from, long long to, long long weight){
    AdjMatrix[from][to] = weight;
}

int main(){
    const long long indexStart = 1; // The index starts from 1
    long long N;
    long long M;
    std::cin >> N >> M;

    GraphMinMaxST g_max(N, "max");
    std::vector<std::vector<long long>> edges;
    for (long long i = 0; i < M; i++) {
        long long u, v, w;
        std::cin >> u >> v >> w;
        edges.push_back({u, v, w});
        g_max.AddEdge(u-indexStart, v-indexStart, w);
        g_max.AddEdge(v-indexStart, u-indexStart, w);
    }
    g_max.PrimMST(0, indexStart);
    // g_max.PrintSum();

    long long bottleneck = g_max.Bottleneck();

    // If there is still more than one way to meet the above two points, the total energy consumption of the network should be minimized. In other words, the sum of bandwidths of the remaining cables should be minimized.

    GraphMinMaxST g_min(N, "min");
    for (long long i = 0; i < M; i++) {
        auto e = edges[i];
        auto u = e[0], v = e[1], w = e[2];
        if (w < bottleneck) continue;

        g_min.AddEdge(u-indexStart, v-indexStart, w);
        g_min.AddEdge(v-indexStart, u-indexStart, w);
    }
    g_min.PrimMST(0, indexStart);
    g_min.PrintSum();


    return 0;
}

/*
input:
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

output:
77
*/