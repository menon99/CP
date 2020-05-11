#include <iostream>
#include <queue>

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int data)
{
    node *ptr = new node;
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct tree
{
    node *root;

    tree()
    {
        root = NULL;
    }

    //insertion
    int insert(int data);

    //deletion
    node *deleteNode(node *root, int data);

    //traversal
    int inOrder(node *root);
    int preOrder(node *root);
    int postOrder(node *root);
    int levelOrder(node *root);

    //find
    node *find(int data);
};

int tree::insert(int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return 1;
    }
    node *temp = root;
    while (true)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = createNode(data);
                break;
            }
            else
                temp = temp->left;
        }
        else if (data > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = createNode(data);
                break;
            }
            else
                temp = temp->right;
        }
    }
    return 1;
}

node *tree::deleteNode(node *root, int data)
{
    if (root->data > data)
        root->left = deleteNode(root->left, data);
    else if (root->data < data)
        root->right = deleteNode(root->right, data);
    else
    {
        //no child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        //one child
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }

        //two children
        else
        {
            //find min in right sub tree
            node *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int tree ::inOrder(node *root)
{
    if (root == NULL)
        return 0;

    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
    return 0;
}

int tree ::postOrder(node *root)
{
    if (root == NULL)
        return 0;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
    return 0;
}

int tree ::preOrder(node *root)
{
    if (root == NULL)
        return 0;
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return 0;
}

int tree ::levelOrder(node *root)
{
    if (root == NULL)
        return 0;
    std::queue<node *> q;
    q.push(root);
    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        std::cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    return 0;
}

node *tree::find(int data)
{
    node *ptr = NULL, *temp = root;
    while (true)
    {
        if(temp->data == data)
        {
            ptr = temp;
            break;
        }
        else if(data > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
        if(temp==NULL)
            break;
    }
    return ptr;
}