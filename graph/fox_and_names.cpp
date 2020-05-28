//https://codeforces.com/problemset/problem/510/C

//kahn's topological sort to find lexicographical relation between strings

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

class graph
{
private:
    int nodes;
    vector<unordered_set<int>> incomingEdges;
    vector<unordered_set<int>> outgoingEdges;

public:
    graph(int n)
    {
        nodes = n;
        incomingEdges.resize(n + 1);
        outgoingEdges.resize(n + 1);
    }
    int getNumNodes()
    {
        return nodes;
    }
    void addEdge(int v1, int v2)
    {
        incomingEdges[v2].insert(v1);
        outgoingEdges[v1].insert(v2);
    }
    unordered_set<int> getIncomingEdges(int vertex)
    {
        return incomingEdges[vertex];
    }
    unordered_set<int> getOutgoingEdges(int vertex)
    {
        return outgoingEdges[vertex];
    }
    void removeIncoming(int v1, int v2)
    {
        incomingEdges[v1].erase(v2);
    }
};

string getOrder(graph &g1)
{
    string order = "";

    stack<int> next_vertex;

    int n = g1.getNumNodes(), v1;

    for (v1 = 1; v1 <= n; v1++)
    {
        if (!g1.getIncomingEdges(v1).size())
            next_vertex.push(v1);
    }

    while (!next_vertex.empty())
    {
        v1 = next_vertex.top();
        next_vertex.pop();

        order += (v1 + 96);

        for (int v2 : g1.getOutgoingEdges(v1))
        {
            g1.removeIncoming(v2, v1);
            if (!g1.getIncomingEdges(v2).size())
                next_vertex.push(v2);
        }
    }

    if (order.length() == 26)
        return order;
    else
        return "Impossible";
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    graph g1(26);

    int n;
    cin >> n;

    string name, names[n];

    for (int i = 0; i < n; i++)
    {
        cin >> name;
        names[i] = name;
    }

    bool main_flag = false, flag;
    int pos, l1, l2;

    for (int i = 0; i < n - 1; i++)
    {
        if (names[i] == names[i + 1])
            continue;

        flag = false;
        pos = 0;
        l1 = names[i].length();
        l2 = names[i + 1].length();

        while (pos < l1 && pos < l2)
        {
            if (names[i][pos] != names[i + 1][pos])
            {
                flag = true;
                break;
            }
            pos++;
        }

        if (flag)
            g1.addEdge(names[i][pos] - 96, names[i + 1][pos] - 96);
        else if (l1 < l2)
            continue;
        else if (l2 < l1)
        {
            main_flag = true;
            break;
        }
    }

    if (main_flag)
        cout << "Impossible\n";
    else
        cout << getOrder(g1) << endl;

    return 0;
}
