#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

TreeNode<int> *takeInput()
{
    int rootData;
    // cout << "EnterData";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    // cout << "Enter num of children of" << root->data;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

int main()
{
    // making nodes
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);
    // // making connections
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // // print tree
    TreeNode<int> *root = takeInput();

    printTree(root);

    return 0;
}