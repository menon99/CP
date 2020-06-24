// Ford-Fulkerson and Edmond Karp Max Flow Min Cut algorithm
// Max flow is defined as the maximum amount of substance that can flow from source to sink.

// Two constraints are to be kept in mind:
// 1. Amount of substance entering any node in the path should also leave it. Except for source and sink.
// 2. The maximum amount that can flow through from A to B is the edge weight between A and B.

#include <iostream>
#include "graph.h"

int maxFlow(graph &g1)
{
    int max_flow = 0;

    while (true)
    {
        //bfs traversal to find all possible augmented paths from source to sink.

        vector<bool> visited(g1.getNumNodes() + 1);
        queue<int> q1;
        vector<int> parent(g1.getNumNodes() + 1, -1);
        int node, min_val = INT32_MAX, d;
        bool flag = false;

        //Assuming source is vertex 1 and sink is last vertex.

        q1.push(1);
        visited[1] = true;

        while (!q1.empty())
        {
            node = q1.front();
            q1.pop();

            for (auto m : g1.getEdges(node))
            {
                if (m.second > 0 && !visited[m.first])
                {
                    parent[m.first] = node;
                    visited[m.first] = true;
                    q1.push(m.first);

                    if (m.first == g1.getNumNodes())
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) //already reached sink so break
                break;
        }
        if (!flag) //queue is empty and sink has not been reached. No more augmented paths to explore.
            break;

        node = g1.getNumNodes();
        while (parent[node] != -1)
        {
            // minimum of all edge weights in the augmented path is the amount
            // that can flow through that path

            min_val = min(min_val, g1.getDist(parent[node], node));
            node = parent[node];
        }

        max_flow += min_val; //Add that min value to answer.

        node = g1.getNumNodes();

        while (parent[node] != -1)
        {
            d = g1.getDist(parent[node], node);
            g1.addEdge(parent[node], node, d - min_val); //subtract min val from each edge involved in augmented path

            //add min val to residual edge

            d = g1.getDist(node, parent[node]);
            if (d == INT32_MAX)
                g1.addEdge(node, parent[node], min_val);
            else
                g1.addEdge(node, parent[node], d + min_val);

            node = parent[node];
        }
    }

    return max_flow;
}

int main(int argc, char const *argv[])
{
    graph g1(7);
    g1.addEdge(1, 2, 3);
    g1.addEdge(1, 4, 3);
    g1.addEdge(2, 3, 4);
    g1.addEdge(3, 1, 3);
    g1.addEdge(3, 4, 1);
    g1.addEdge(3, 5, 2);
    g1.addEdge(5, 2, 1);
    g1.addEdge(4, 5, 2);
    g1.addEdge(5, 7, 1);
    g1.addEdge(6, 7, 9);
    g1.addEdge(4, 6, 6);

    // graph g1(4);
    // g1.addEdge(1,3,2);
    // g1.addEdge(1,2,1);
    // g1.addEdge(3,2,3);
    // g1.addEdge(3,4,1);
    // g1.addEdge(2,4,2);

    cout << "max flow possible is " << maxFlow(g1) << endl;
    return 0;
}