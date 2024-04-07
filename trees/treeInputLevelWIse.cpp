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
    /*When we simply call delete on the root this custom destructor is called to delete all the children recursively in post order*/
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children;
        }
    }
};

TreeNode<int> *takeIn()
{
    int rootData;
    cin >> rootData;
    // creating root node
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> q;
    // pushing the root node into the queue
    q.push(root);

    while (q.size() != 0)
    {
        // taking the root node as the front and getting all its children
        TreeNode<int> *front = q.front();
        q.pop();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            /* allocating dynamically because statically allocated objects have scope within their blocks only. After the first iteration the statically allocated object would have been lost
             */
            front->children.push_back(child);
            q.push(child);
        }
    }

    return root;
}

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
// bfs
void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    // cout<<root->data;
    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        cout << temp->data << ":";
        for (int i = 0; i < temp->children.size(); i++)
        {
            if (i + 1 != temp->children.size())
                cout << temp->children[i]->data << ",";
            else
                cout << temp->children[i]->data;
            q.push(temp->children[i]);
        }
        cout << endl;
    }
}

int numNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;
    ans += root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    TreeNode<int> *m = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *m2 = maxDataNode(root->children[i]);
        if (m2->data > m->data)
            m = m2;
    }
    return m;
}

int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int h = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        int h2 = 1 + getHeight(root->children[i]);
        if (h2 > h)
            h = h2;
    }
    return h;
}

void printLevel(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->data << ' ';
    for (int i = 0; i < root->children.size(); i++)
    {
        printLevel(root->children[i], k - 1);
    }
}

int getLeafNodeCount(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
        return 1;
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLeafNodeCount(root->children[i]);
    }
    return count;
}

void printPostOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
}
/*We always delete a tree in a post order because if delete the root first then we wont be able to
traverse to its children and delete them*/
void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{

    TreeNode<int> *root = takeIn();
    printLevelWise(root);
    // printTree(root);
    // printPostOrder(root);

    cout << endl
         << getLeafNodeCount(root);

    // deleteTree(root);

    delete root;

    return 0;
}