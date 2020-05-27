#include <iostream>
#include "graph.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class compareDistance
{
public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

unordered_map<int, int> prims(graph g1)
{
    unordered_map<int, int> edges;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compareDistance> min_edges;
    unordered_set<int> not_visited;
    int n = g1.getNumNodes(), node, total = 0;
    for (int i = 1; i <= n; i++)
        not_visited.insert(i);
    while (!not_visited.empty())
    {
        for (int i : not_visited)
        {
            min_edges.push({i, 0});
            break;
        }
        while (!min_edges.empty() && !not_visited.empty())
        {
            node = min_edges.top().first;
            min_edges.pop();
            if (not_visited.find(node) != not_visited.end())
            {
                not_visited.erase(node);
                for (auto m : g1.getEdges(node))
                {
                    if (not_visited.find(m.first) != not_visited.end())
                    {
                        min_edges.push(m);
                        if (edges.find(m.first) == edges.end())
                        {
                            edges[m.first] = node;
                            total += m.second;
                        }
                        else if (g1.getDist(edges[m.first], m.first) > g1.getDist(node, m.first))
                        {
                            total -= g1.getDist(edges[m.first],m.first);
                            total += g1.getDist(node,m.first);
                            edges[m.first] = node;
                        }
                    }
                }
            }
        }
    }
    printf("total cost %d\n", total);
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
    unordered_map<int, int> edges = prims(g1);
    for (auto m : edges)
        printf("edge from %d to % d\n", m.second, m.first);
    return 0;
}