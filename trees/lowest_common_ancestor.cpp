#include <iostream>
#include "tree.h"

using namespace std;

node *lowestCommonAncestor(node *root, int a, int b)
{
    node *temp = root;

    while (true)
    {
        if (temp == NULL)
            break;
        else if (temp->data > a && temp->data > b)
            temp = temp->left;
        else if (temp->data < a && temp->data < b)
            temp = temp->right;
        else if ((temp->data > a && temp->data < b) || (temp->data > b && temp->data < a))
            break;
        else if (temp->data == b || temp->data == a)
            break;
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    tree t1;
    t1.insertData(); //comment this to insert your own data

    /*  //uncomment this to enter your own data
    
    int n, data; //n is no of elements to be inserted
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data; //data to be inserted
        t1.insert(data);
    }
    
    */
    int a, b, k;
    cin >> k; //number of pairs whose ancestors are to be found
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b; //pair whose ancestor is to be found
        node *ancestor = lowestCommonAncestor(t1.root, a, b);
        if (ancestor == NULL)
            cout << "No ancestor found";
        else
            cout << "Ancestor is :" << ancestor->data << endl;
    }
    return 0;
}
