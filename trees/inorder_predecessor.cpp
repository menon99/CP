#include <iostream>
#include "tree.h"

using namespace std;

node *inOrderPredecessor(tree t1, int data)
{
    //predecessor is searched in the left subtree of the node

    //find the node with the data
    node *current = t1.find(data);
    if (current == NULL)
        return NULL;

    //case 1 : current node has left subtree. Find max in left subtree
    if (current->left != NULL)
    {
        node *temp = current->left;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }

    //case 2: current node has no left subtree. So, need to find the deepest parent which is smaller than data
    else
    {
        node *ancestor = NULL;
        node *temp = t1.root;

        //start from root. if temp->data is less than data,then temp could possibly be its predecessor.
        //so we update ancestor to temp and try moving closer to data by going to temp->right
        while (true)
        {
            if(data < temp->data)
                temp = temp->left;
            else if(data > temp->data)
            {
                ancestor = temp;
                temp = temp->right;
            }
            else
                break;
        }
        return ancestor;
    }
}

int main(int argc, char const *argv[])
{
    tree t1;
    t1.insertData(); // comment this to insert your own data

    /* //uncomment this to insert your own data
    int n,data;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >>data;
        t1.insert(data);
    }
    */
   
    int tries,val;
    cin >> tries; // number of nodes whose successor is to be found
    
    while (tries)
    {
        cin >> val; //node whose successor is to be found;
        node *successor = inOrderPredecessor(t1, val);
        if (successor != NULL)
            cout << "predecessor is :" << successor->data << endl;
        else
            cout << "given node has no predecessor" << endl;
        tries--;
    }
    return 0;
}
