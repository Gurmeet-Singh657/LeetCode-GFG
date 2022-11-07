//{ Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */
#include<bits/stdc++.h>
// function to find length of list
int length(node* Node)
{
    if(Node==NULL) return 0;
    node* curr=Node;
    int len=0;
    while(curr!=NULL)
    {
        len++;
        curr=curr->next;
    }
    return len;
}
vector<node*> seggregate(node* head,int pivotIdx)
{
    node* small=new node(-1);
    node* large=new node(-1);
    
    node* curr=head,*sp=small,*lp=large,*pivotNode=head;
    while(pivotIdx-->0)
        pivotNode=pivotNode->next;
    while(curr!=NULL)
    {
        if(curr!=pivotNode)
        {
            if(curr->data<=pivotNode->data)
            {
                sp->next=curr;
                sp=sp->next;
            }
            else
            {
                lp->next=curr;
                lp=lp->next;
            }
        }
        curr=curr->next;
    }
    sp->next=NULL;
    lp->next=NULL;
    pivotNode->next=NULL;
    return {small->next,pivotNode,large->next};
}
vector<node*> mergeSortedLists(vector<node*> leftSortedList,node* pivotNode,vector<node*> rightSortedList)
{
    node* head=NULL,*tail=NULL;
    if(leftSortedList[0]!=NULL && rightSortedList[0]!=NULL)
    {
        leftSortedList[1]->next=pivotNode;
        pivotNode->next=rightSortedList[0];
        head=leftSortedList[0];
        tail=rightSortedList[1];
    }
    else if(leftSortedList[0]!=NULL)
    {
        leftSortedList[1]->next=pivotNode;
        head=leftSortedList[0];
        tail=pivotNode;
    }
    else if(rightSortedList[0]!=NULL)
    {
        pivotNode->next=rightSortedList[0];
        head=pivotNode;
        tail=rightSortedList[1];
    }
    else
    {
        head=tail=pivotNode;
    }
    return {head,tail};
}
vector<node*> QuickSort(node* head)
{
    if(head==NULL || head->next==NULL) 
    return {head,head};
    
    int len=length(head);
    int pivotIdx=len/2;
    
    vector<node*> seggregatedLists=seggregate(head,pivotIdx);
    vector<node*> leftSortedList=QuickSort(seggregatedLists[0]);
    vector<node*> rightSortedList=QuickSort(seggregatedLists[2]);
    return mergeSortedLists(leftSortedList,seggregatedLists[1],rightSortedList);
}
//you have to complete this function
void quickSort(struct node **headRef) {
    vector<node*> ans=QuickSort(*headRef);
    *headRef=ans[0];
}