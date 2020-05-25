#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char const *argv[])
{
    graph g1 = getGraph();
    cout << "bfs traversal\n";
    g1.bfs(1);
    cout << "dfs traversal\n";
    g1.dfs(3);
    return 0;
}