#include <iostream>
#include "graph.h"
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    Node *parent;
    vector<Node *> children;
    Node()
    {
        parent = NULL;
    }
};

bool Union(Node *p1, Node *p2)
{
    if (p1 == p2)
        return false;
    if (p1->children.size() >= p2->children.size())
    {
        p2->parent = p1;
        p1->children.push_back(p2);
        for (auto p : p2->children)
        {
            p->parent = p1;
            p1->children.push_back(p);
        }
        p2->children.clear();
    }
    else
    {
        p1->parent = p2;
        p2->children.push_back(p1);
        for(auto p : p1->children)
        {
            p->parent = p2;
            p2->children.push_back(p);
        }
        p1->children.clear();
    }
    return true;
}

Node *find(Node *p1)
{
    if (!p1->parent)
        return p1;
    return p1->parent;
}

class Edge
{
public:
    int node1, node2, dist;
    Edge(int n1, int n2, int d)
    {
        node1 = n1;
        node2 = n2;
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

vector<pair<int, int>> kruskal(graph &g1)
{
    vector<pair<int, int>> edges;
    int total = 0;
    priority_queue<Edge, vector<Edge>, compareDist> min_edges;
    int t_sets = g1.getNumNodes();
    vector<Node *> nodes(t_sets + 1);
    for (int i = 1; i <= t_sets; i++)
    {
        nodes[i] = new Node();
        for (auto m : g1.getEdges(i))
            min_edges.push(Edge(i, m.first, m.second));
    }
    int n1, n2;
    while (t_sets != 1 && !min_edges.empty())
    {
        n1 = min_edges.top().node1;
        n2 = min_edges.top().node2;
        if (Union(find(nodes[n1]), find(nodes[n2])))
        {
            edges.push_back({n2, n1});
            total += min_edges.top().dist;
            t_sets -= 1;
        }
        min_edges.pop();
    }
    printf("total cost is %d\n", total);
    return edges;
}

int main(int argc, char const *argv[])
{
    //graph g1 = getGraph();
    graph g1(6);
    g1.insert(1, {{2, 3}, {4, 1}});
    g1.insert(2, {{1, 3}, {4, 3}, {3, 1}});
    g1.insert(3, {{2, 1}, {4, 1}, {5, 5}, {6, 4}});
    g1.insert(4, {{1, 1}, {2, 3}, {5, 6}, {3, 1}});
    g1.insert(5, {{4, 6}, {6, 2}, {3, 5}});
    g1.insert(6, {{5, 2}, {3, 4}});
    vector<pair<int, int>> edges = kruskal(g1);
    for (auto m : edges)
        printf("edge from %d to % d\n", m.second, m.first);
    return 0;
}
