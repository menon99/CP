#include <iostream>
#include "tree.h"
#include <stack>

using namespace std;

void inOrderStack(node * root)
{
    if(root == NULL)
        return;
    stack<node*> s1;
    node * temp = root;
    while(temp!= NULL || !s1.empty())
    {
        while(temp!=NULL)
        {
            s1.push(temp);
            temp = temp->left;
        }
        temp = s1.top();
        s1.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main(int argc, char const *argv[])
{
    tree t1;
    int n,data;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >>data;
        t1.insert(data);
    }
    cout << "InOrder traversal\n";
    inOrderStack(t1.root);
    cout << "\n";
    return 0;
}