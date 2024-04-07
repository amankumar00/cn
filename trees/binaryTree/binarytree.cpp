#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *right;
    BinaryTreeNode *left;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    };
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    };
};

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        q.pop();
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftData);
            temp->left = leftChild;
            q.push(leftChild);
        }
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightData);
            temp->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}
BinaryTreeNode<int> *createTree(vector<int> &arr)
{
    // cout << arr[0];
    // int data = arr[0];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[0]);
    // cout << root->data;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(arr[i++]);
        front->left = leftChild;
        q.push(leftChild);
        BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(arr[i++]);
        front->right = rightChild;

        q.push(rightChild);
        // cout << leftChild->data << " " << rightChild->data << " ";.
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        q.pop();
        cout << temp->data << ":";

        if (temp->left)
        {
            cout << "L:" << temp->left->data << ",";
            q.push(temp->left);
        }
        else
        {
            cout << "L:-1,";
        }
        if (temp->right)
        {
            q.push(temp->right);
            cout << temp->right->data << endl;
        }
        else
        {
            cout << "R:-1\n";
        }
    }
}

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }

    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}
// 1 2 3 4 -1 -1 8 -1 -1 -1 -1
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // int h1=0,h2=0;
    // if(root->left!=NULL){
    int h1 = height(root->left);
    // }
    // if(root->right!=NULL{}
    int h2 = height(root->right);

    return 1 + max(h1, h2);
}

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

vector<int> preOrder(BinaryTreeNode<int> *root)
{
    static vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    v.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);

    return v;
}
void postOrder(BinaryTreeNode<int> *root)
{
    //    static vector<int> v;
    if (root == NULL)
    {
        return;
    }
    // v.push_back(root->data);
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
    // return ;
}
int main()
{
    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // // printTree(root);
    // // printLevelWise(root);
    // // int num;
    // // cin>>num;
    // // cout<<isNodePresent(root,num);
    // // cout<<height(root);
    // // mirrorBinaryTree(root);
    // // printLevelWise(root);
    // // preOrder(root);
    // vector<int> v = preOrder(root);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << ' ';
    // }

    vector<int> v;

    int p;

    while (cin >> p)
    {
        v.push_back(p);
    }
    // cout << v[0];
    BinaryTreeNode<int> *root = createTree(v);
    printTree(root);

    return 0;
}
