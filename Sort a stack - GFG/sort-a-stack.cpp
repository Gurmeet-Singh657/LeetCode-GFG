//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
void SortedInsert(stack<int>& s,int curr)
{
    if(s.empty() || curr>=s.top())
    {
        s.push(curr);
        return;
    }
    int ele=s.top();
    s.pop();
    SortedInsert(s,curr);
    s.push(ele);
}
void SortStack(stack<int>& s)
{
    if(s.empty())
    return;
    int curr=s.top();
    s.pop();
    SortStack(s);
    SortedInsert(s,curr);
}
/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   SortStack(s);
}