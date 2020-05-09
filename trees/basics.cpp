#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int n, data;
    cin >> n; //number of elements to be inserted
    cout << "n is " << n << endl;
    tree t1;

    for (size_t i = 0; i < n; i++)
    {
        cin >> data; //data to be inserted
        t1.insert(data);
        cout << "\n";
    }

    cout << "inOrder traversal :";
    t1.inOrder(t1.root);
    cout << "\npostOrder traversal :";
    t1.postOrder(t1.root);
    cout << "\npreOrder traversal :";
    t1.preOrder(t1.root);
    cout << "\nlevelOrder traversal :";
    t1.levelOrder(t1.root);
    cout << "\n";

    cin >> n; // number of elements to be deleted
    for (size_t i = 0; i < n; i++)
    {
        cin >> data; // data to be deleted
        t1.deleteNode(t1.root, data);
        t1.inOrder(t1.root);
        cout << "\nroot is " << t1.root->data << "\n";
    }

    return 0;
}
