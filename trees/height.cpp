#include <iostream>
#include "tree.h"

using namespace std;

int height(node *root, int h)
{
    if (root == NULL)
        return h;
    return max(height(root->left, h + 1), height(root->right, h + 1));
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
   
    cout << "height of tree is :" << height(t1.root,0) << endl;
    return 0;
}
