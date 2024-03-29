//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node* reverse(Node* head)
    {
        Node* prev=NULL;
        while(head!=NULL)
        {
            Node* ahead=head->next;
            head->next=prev;
            prev=head;
            head=ahead;
        }
        return prev;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        if(head==NULL || head->next==NULL) return head;
         Node* fast=head,*slow=head;
         while(fast->next!=NULL && fast->next->next!=NULL)
         {
             slow=slow->next;
             fast=fast->next->next;
         }
         Node* mid=slow;
         mid->next=reverse(mid->next);
         Node* first=head;
         Node* second=mid->next;
         while(second!=NULL)
         {
             second->data=second->data-first->data;
             second=second->next;
             first=first->next;
         }
         mid->next=reverse(mid->next);
         return reverse(head);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends