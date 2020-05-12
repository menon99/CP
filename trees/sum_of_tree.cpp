#include <iostream>
#include "tree.h"

using namespace std;

int treeSum(node *root)
{
    if(root == NULL)
        return 0;
    return root->data + treeSum(root->left) + treeSum(root->right);
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
   
    cout << "sum is :" << treeSum(t1.root) << endl;
    return 0;
}
