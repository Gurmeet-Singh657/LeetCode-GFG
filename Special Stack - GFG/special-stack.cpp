//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

#include<bits/stdc++.h>
int mini=INT_MAX;
void push(stack<int>& s, int a){
	if(a<=mini)
	{
    	s.push(2*a-mini);
    	mini=a;
	}
	else
	{
	    s.push(a);
	}
}

bool isFull(stack<int>& s,int n){
	return s.size()==n;
}

bool isEmpty(stack<int>& s){
	return s.size()==0;
}

int pop(stack<int>& s){
    if(s.size()==0) return -1;
	int curr=s.top();
	if(curr<=mini)
	{
	    mini=2*mini-curr;
	}
	s.pop();
	return curr;
}

int getMin(stack<int>& s){
	return mini;
}