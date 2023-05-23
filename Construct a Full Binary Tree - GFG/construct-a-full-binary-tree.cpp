//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* f(int i1,int j1,int i2,int j2,int pre[],int preMirror[])
    {
        if(i1==j1) return new Node(pre[i1]);
        int num1=preMirror[i2+1];
        int mid1;
        for(int i=i1+1;i<=j1;i++)
        {
            if(num1==pre[i])
            {
                mid1=i;
                break;
            }
        }
        int num2=pre[i1+1];
        int mid2;
        for(int i=i2+1;i<=j2;i++)
        {
            if(num2==preMirror[i])
            {
                mid2=i;
                break;
            }
        }
        Node* curr=new Node(pre[i1]);
        curr->left=f(i1+1,mid1-1,mid2,j2,pre,preMirror);
        curr->right=f(mid1,j1,i2+1,mid2-1,pre,preMirror);
        return curr;
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        return f(0,size-1,0,size-1,pre,preMirror);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends