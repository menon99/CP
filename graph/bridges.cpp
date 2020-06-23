//Bridges and cut edges in an undirected graph using tarjan's algorithm

#include <iostream>
#include "graph.h"
#include <unordered_set>

using namespace std;

void dfs(graph &g1, vector<int> &start_time, vector<int> &low_time, vector<bool> &visited, int node, int parent, int &timer)
{
    start_time[node] = timer;
    low_time[node] = timer;
    timer++;
    for (auto m : g1.getEdges(node))
    {
        if (!visited[m.first])
        {
            visited[m.first] = true;
            dfs(g1, start_time, low_time, visited, m.first, node, timer);
            if (start_time[node] < low_time[m.first])
                printf("bridge bw %d and %d\n", node, m.first);
            else
                low_time[node] = min(low_time[node],low_time[m.first]);
        }
        if (m.first != parent)
            low_time[node] = min(low_time[node], start_time[m.first]);
    }
}

void bridges(graph &g1)
{
    int timer = 0, n = g1.getNumNodes();
    vector<int> start_time(n + 1, 0);
    vector<int> low_time(n + 1, 0);
    vector<bool> visited (n+1,false);
    visited[4] = true;

    dfs(g1, start_time, low_time, visited, 4, -1, timer);
}

int main(int argc, char const *argv[])
{
    graph g1(15);
    g1.addUndirected(1, {2, 3});
    g1.addUndirected(2, {3, 5, 6});
    g1.addUndirected(3, {4, 7, 8});
    g1.addUndirected(4, {5, 6});
    g1.addUndirected(6, {7});
    g1.addUndirected(8, {9, 10});
    g1.addUndirected(9, {10, 11});
    g1.addUndirected(10, {12});
    g1.addUndirected(11, {12, 13});
    g1.addUndirected(13, {14, 15});
    g1.addUndirected(14, {15});

    bridges(g1);
    return 0;
}
