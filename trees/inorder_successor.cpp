#include <iostream>
#include "tree.h"

using namespace std;

node *inOrderSuccessor(tree t1, int data)
{
    //successor is searched in the right subtree of the node

    //find node
    node *current = t1.find(data);
    if (current == NULL)
        return NULL;

    //case 1 : current node has right subtree. Find min in right subtree
    if (current->right != NULL)
    {
        node *temp = current->right;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    //case 2: current node has no right subtree. So, need to find the deepest parent which is greater than current node.
    else
    {
        node *ancestor = NULL;
        node *temp = t1.root;

        //start from root and check if temp is > data. if true, then temp could be its successor.
        //Try moving closer to data and update ancestor,by going to temp->left
        while (true)
        {
            if (data < temp->data)
            {
                ancestor = temp;
                temp = temp->left;
            }
            else if (data > temp->data)
                temp = temp->right;
            else
                break;
        }
        return ancestor;
    }
}

int main(int argc, char const *argv[])
{
    int n, data;
    cin >> n; //number of elements to be inserted
    tree t1;

    for (size_t i = 0; i < n; i++)
    {
        cin >> data; //data to be inserted
        t1.insert(data);
    }
    int tries;
    cin >> tries; // number of nodes whose successor is to be found
    while (tries)
    {
        cin >> data; //node whose successor is to be found;
        node *successor = inOrderSuccessor(t1, data);
        if (successor != NULL)
            cout << "successor is :" << successor->data << endl;
        else
            cout << "given node has no successor" << endl;
        tries--;
    }
    return 0;
}
