#include <iostream>
#include "tree.h"

using namespace std;

int d = 0;

int diameter(node* root,int h)
{
    if(root == NULL)
        return h;
    int leftHeight = diameter(root->left,h+1);
    int rightHeight = diameter(root->right, h+1);
    int diameter = leftHeight + rightHeight - 2 - 2*h;
    d = max(d,diameter);
    return max(leftHeight,rightHeight);
}

int main(int argc, char const *argv[])
{
    tree t1;
    t1.insertData();
    diameter(t1.root,0);
    cout << "diameter is :" << d << endl;
    return 0;
}
