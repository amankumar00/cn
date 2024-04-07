#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
bool isPresent(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    static bool ans = false;
    for (int i = 0; i < root->children.size(); i++)
    {

        isPresent(root->children[i], x);
    }
    if (root->data == x)
    {
        ans = true;
    }
    cout << root->data << " ";

    return ans;
}
// cn solution
bool isPresent2(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    static bool ans = false;
    for (int i = 0; i < root->children.size(); i++)
    {

        isPresent2(root->children[i], x);
    }
    if (root->data == x)
    {
        ans = true;
    }
    cout << root->data << " ";

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
        ans += root->children[i]->data;
    }
    return ans;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return root;
    }
    // if(root->children.size()==0){
    //     return root;
    // }
    static int max_sum = sumOfNodes(root);
    static TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << sumOfNodes(root->children[i]) << " ";
        if (sumOfNodes(root->children[i]) >= max_sum)
        {
            // cout<<max_sum<<' ';
            // cout<<root->children[i]->data<<' ';
            max = root->children[i];
            // cout<<max->data<<endl;
            max_sum = sumOfNodes(root->children[i]);
        }
        if (root->children[i]->children.size() != 0)
            maxSumNode(root->children[i]);
    }

    return max;
}

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    static TreeNode<int> *ans = NULL;
    static int diff = INT32_MAX;
    if (root->data > x && (root->data - x) < diff)
        ans = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        if (root->children[i]->data > x && (root->children[i]->data - x) < diff)
        {
            ans = root->children[i];
            diff = root->children[i]->data - x;
        }
        getNextLargerElement(root->children[i], x);
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
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    // if(root->children.size()==0){
    //     return NULL;
    // }
    static TreeNode<int> *max1 = maxDataNode(root);
    // cout << max1->data << "max ";
    TreeNode<int> *max2 = root;
    
    for (int i = 0; i < root->children.size(); i++)
    {
        // cout<<max1->data<<' ';
        //  cout<<root->children[i]->data<<' ';
         TreeNode<int> *temp = getSecondLargestNode(root->children[i]);
        //  cout<< temp->data<<' ';
         if(temp->data>max2->data&&temp->data<max1->data)
            max2 = temp;
    }
    // cout<<root->data<<' ';
    
    return max2;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);
    // getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << 0;
    }
}
/*
1
3
2
3
4
2
5
6
1
7
1
8
5
9
10
11
12
13
0
0
0
*/