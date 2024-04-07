#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main()
{
    // statically
    Node *n1= new Node(15);
    Node *head = n1;
    Node *n2 = new Node(16);
    Node *n3 = new Node(17);
    Node *n4 = new Node(18);
    Node *n5 = new Node(19);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    print(n2);

    // n1.next = &n2;
    // // n1->next = n2;  will not work for statically allocated nodes
    // // cout<<n1.data<<" "<<n2.data<<endl;

    // cout<<head->data<<" "<<head->next->data;
    // // dynamically

    // Node *n3 = new Node(17);
    // Node *head = n3;
    // Node *n4 = new Node(18);
    // n3->next = n4;                  //only works with dynamically allocated memory blocks as n3 and n4 are memory addresses
    
    return 0;
}