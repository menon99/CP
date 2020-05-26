#include <iostream>
#include "graph.h"
#include <unordered_set>

using namespace std;

class Edge
{
public:
    int node1, dist;
    Edge(int n1, int d)
    {
        node1 = n1;
        dist = d;
    }
};

class compareDist
{
public:
    bool operator()(Edge &e1, Edge &e2)
    {
        return e1.dist > e2.dist;
    }
};

void dijkstra(graph g1, int start, vector<int> &dist, vector<int> &link)
{
    dist[start] = 0;
    link[start] = -1;
    priority_queue<Edge, vector<Edge>, compareDist> min_edge;
    unordered_set<int> not_visited;
    for (int i = 1; i <= g1.getNumNodes(); i++)
        not_visited.insert(i);
    min_edge.push(Edge(start, 0));
    int node, cost;
    while (!not_visited.empty() && !min_edge.empty())
    {
        node = min_edge.top().node1;
        cost = min_edge.top().dist;
        not_visited.erase(node);
        min_edge.pop();
        for (auto m : g1.getEdges(node))
        {
            if (not_visited.find(m.first) != not_visited.end() && cost + m.second < dist[m.first])
            {
                dist[m.first] = cost + m.second;
                link[m.first] = node;
                min_edge.push(Edge(m.first, cost + m.second));
            }
        }
    }
}

void printPath(int node, vector<int> &link)
{
    string s = to_string(node);
    while (link[node] != -1)
    {
        s += " >- " + to_string(link[node]);
        node = link[node];
    }
    for(auto i = s.rbegin(); i != s.rend(); i++)
        cout << *i;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    graph g1 = getGraph();
    vector<int> dist(g1.getNumNodes() + 1, INT32_MAX);
    vector<int> link(g1.getNumNodes() + 1, INT32_MAX);
    int start = 7;
    dijkstra(g1, start, dist, link);
    for (int i = 1; i <= g1.getNumNodes(); i++)
    {
        if (i == start)
            continue;
        else if (dist[i] == INT32_MAX)
            printf("no path available from %d to %d\n", start, i);
        else
        {
            printf("cost from %d to %d is %d path is : ", start, i, dist[i]);
            printPath(i, link);
        }
    }
    return 0;
}