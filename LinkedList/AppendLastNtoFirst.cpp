#include <iostream>

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

using namespace std;

Node *appendLastNToFirst(Node *head, int n)
{
   Node *temp = head;
   Node *tail = head;
    if(temp==NULL){
        return head;
    }
//    cout<<head->data<<endl;
	int t =0;
   while(t<(n-1)&&temp !=NULL){
	   t++;
	   temp = temp->next;
   }
   while(tail !=  NULL&&tail->next!=NULL){
	   tail = tail-> next;
   }

    // cout<<tail->data<<endl;
    // cout<<temp->data<<endl;
    // cout<<head->data<<endl;
	tail->next = head;
	head = temp->next;
	temp->next = NULL;
	return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}