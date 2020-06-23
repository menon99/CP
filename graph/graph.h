#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class graph
{
private:
    int nodes;

public:
    vector<unordered_map<int, int>> g1;
    //constructor number of nodes in graph
    graph(int n)
    {
        nodes = n;
        g1.resize(n + 1);
    }

    //returns no. of nodes in graph
    int getNumNodes()
    {
        return nodes;
    }

    //returns edges of a node
    unordered_map<int,int> getEdges(int node)
    {
        return g1[node];
    }

    //returns distance between two nodes if exists
    int getDist(int node1,int node2)
    {
        if(g1[node1].find(node2) != g1[node1].end())
            return g1[node1][node2];
        return INT32_MAX;
    }

    //inserts all edges from a given vertex
    bool insert(int index, unordered_map<int, int> m1)
    {
        g1[index] = m1;
        return true;
    }

    //edge from v1 to v2 with cost 
    bool addEdge(int v1, int v2, int cost = 0)
    {
        g1[v1][v2] = cost;
        return true;
    }

    void addUndirectedEdge(int v1, int v2)
    {
        g1[v1][v2] = 0;
        g1[v2][v1] = 0;
    }

    void addUndirected(int v1,vector<int> l)
    {
        for(int i : l)
        {
            g1[v1][i] = 0;
            g1[i][v1] = 0;
        }
    }

    //breadth first search traversal
    void bfs(int start)
    {
        queue<pair<int, int>> q1;
        vector<bool> visited(nodes + 1, false);
        q1.push({start, 0});
        visited[start] = true;
        int node, cost;
        while (!q1.empty())
        {
            node = q1.front().first;
            cost = q1.front().second;
            q1.pop();
            printf("visited node %d with cost %d\n", node, cost);
            for (auto m : g1[node])
            {
                if (!visited[m.first])
                    q1.push({m.first, cost + 1});
                visited[m.first] = true;
            }
        }
    }

    //depth first search traversal
    void dfs(int start)
    {
        vector<bool> visited(nodes + 1, false);
        stack<pair<int, int>> s1;
        s1.push({start, 0});
        visited[start] = true;
        int node, cost;
        while (!s1.empty())
        {
            node = s1.top().first;
            cost = s1.top().second;
            s1.pop();
            printf("visited node %d with cost %d\n", node, cost);
            for (auto m : g1[node])
            {
                if (!visited[m.first])
                    s1.push({m.first, cost + 1});
                visited[m.first] = true;
            }
        }
    }
};

//utility function to get a readymade graph
graph getGraph()
{
    graph g1(7);
    g1.insert(1, {{2, 3}, {4, 5}, {3, 1}});
    g1.insert(2, {{5, 2}, {6, 8}, {7, 2}});
    g1.insert(3, {{1, 2}});
    g1.insert(7, {{6, 5}, {2, 3}});
    g1.insert(6, {{5, 4}, {6, 1}, {7, 1}});
    g1.insert(4, {{5, 2}});
    g1.insert(5, {{1, 2}, {2, 7}, {3, 8}, {4, 3}, {6, 7}, {7, 6}});
    return g1;
}