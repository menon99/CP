#include <iostream>
#include "graph.h"
#include <stack>
#include <unordered_set>

void recurse(int node, graph& g1, unordered_set<int>& visited, stack<int>& topology)
{
    for(auto m : g1.getEdges(node))
    {
        if(visited.find(m.first) == visited.end())
        {
            visited.insert(m.first);
            recurse(m.first,g1,visited,topology);
        }
    }
    topology.push(node);
}


void topologicalSort(graph g1)
{
    unordered_set<int> visited;
    stack<int> topology;
    for(int i = 1; i <= g1.getNumNodes(); i++)
    {
        if(visited.find(i) == visited.end())
        {
            visited.insert(i);
            recurse(i,g1,visited,topology);
        }
    }
    cout << "Build order is : ";
    while(!topology.empty())
    {
        cout << topology.top() << " ";
        topology.pop();
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    graph g1(8);
    g1.addEdge(1,3);
    g1.addEdge(2,3);
    g1.addEdge(3,5);
    g1.addEdge(2,4);
    g1.addEdge(5,6);
    g1.addEdge(5,8);
    g1.addEdge(6,7);
    g1.addEdge(4,6);
    topologicalSort(g1);
    return 0;
}
