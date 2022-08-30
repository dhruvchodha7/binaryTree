// tree is a non linear data structure

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    cout << "For left side " << data << endl;
    root->left = buildTree(root->left);
    cout << "For right side " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversals(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp = NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(node *root)
{
    stack<node *> s;
    queue<node *> q;
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);

        if (root->right)
            q.push(root->right);
        if (root->left)
            q.push(root->left);
    }
    while (!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }
}

void iterativeInorder(node *root)
{
    stack<node *> s;
    node *curr = root;
    while (!s.empty() || curr != nullptr)
    {
        if (curr != nullptr){
            s.push(curr);
            curr = curr->left;
        }else{
            curr = s.top();
            s.pop();
            cout<<curr->data;
            curr = curr->right;
        }
    }
}

int main()
{
    node *root = NULL;

    // creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order
    cout << "Printing level order traversal ";
    levelOrderTraversals(root);
    return 0;
}