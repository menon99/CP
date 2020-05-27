#include <iostream>
#include <stack>
#include "graph.h"
#include <unordered_set>
#include <vector>

using namespace std;

void topological_khan(graph g1)
{
    stack<int> next;
    int vertex , n = g1.getNumNodes();
    vector<unordered_set<int>> incoming (n + 1);
    
    for(int i = 1; i <= n; i++)
    {
        for(auto m : g1.getEdges(i))
        {
            vertex = m.first;
            incoming[vertex].insert(i);
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(incoming[i].size() == 0)
            next.push(i);
    }
    
    cout << "build order is : ";
    while(!next.empty())
    {
        vertex = next.top();
        next.pop();
        cout << vertex << " ";
        for(auto m : g1.getEdges(vertex))
        {
            incoming[m.first].erase(vertex);
            if(incoming[m.first].size() == 0)
                next.push(m.first);
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    graph g1(11);
    g1.addEdge(5, 2);
    g1.addEdge(5, 6);
    g1.addEdge(2, 1);
    g1.addEdge(2, 3);
    g1.addEdge(1, 4);
    g1.addEdge(6, 4);
    g1.addEdge(3, 7);
    g1.addEdge(6, 8);
    g1.addEdge(4, 7);
    g1.addEdge(9, 8);
    g1.addEdge(9, 11);
    g1.addEdge(11, 8);
    g1.addEdge(8, 10);
    g1.addEdge(10, 7);
    topological_khan(g1);
    return 0;
}
