#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *takeInput()
{

    int n;
    cin >> n;
    Node *head = NULL;
    Node *temp;
    while (n != -1)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
        cin >> n;
    }
    return head;
}
// faulty code
void insert(Node *head, int n, int data)
{
    Node *temp = head;
    while (n > 1 && temp != NULL)
    {
        n--;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        Node *newNode = new Node(data);
        Node *t_temp = temp->next->next;
        temp->next = newNode;
        newNode->next = t_temp;
    }
}

Node *deleteNode(Node *head, int pos)
{
    Node *temp = head;
    int i = 0;
    if (pos == 0 && temp != NULL)
    {
        head = head->next;
    }
    else
    {
        while (temp != NULL && i < (pos - 1))
        {
            i++;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            Node *a = temp->next;
            Node *b = a->next;

            temp->next = b;
            delete a;
        }
    }

    return head;
}

int main()
{
    Node *head;
    head = takeInput();
    print(head);
    int n, data;
    cin >> n >> data;
    cout << endl;
    insert(head, n, data);
    // head = deleteNode(head,n);
    // Node *temp = head;
    // head->next->next = head;
    // head = head->next;
    // temp->next = NULL;
    print(head);
    return 0;
}