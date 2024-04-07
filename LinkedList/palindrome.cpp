
#include <bits/stdc++.h>

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
Node *reverseLinkedListRec(Node *head)
{
   if(head==NULL){
	   return NULL;
   }
	if(head->next ==NULL){
		return head;
	}
	Node *temp =reverseLinkedListRec(head->next);
	Node * t2 = head->next;
	t2->next = head;
	head->next = NULL;
	return temp;
}
bool isPalindrome(Node *head)
{
    Node *fast = head;
	Node *slow = head;
    int count = 0;
    while(fast!=NULL&&fast->next!=NULL){
        count++;
        fast = fast->next;
    }

    fast = head;
    if(count%2==0){
        while(fast!=NULL&&fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	    }
    }
    else{
        while(fast!=NULL&&fast->next->next!=NULL){
            fast = fast->next->next;
		    slow = slow->next;
        }
    }
	Node *last = reverseLinkedListRec(slow);
	cout<<last->data<<" "<<head->data<<endl;
	while(head!=slow&&last!=slow){
		if(head->data!=last->data){
			return false;
		}
		head = head->next;
		last = last->next;
	}
	
	return true;

    

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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}

