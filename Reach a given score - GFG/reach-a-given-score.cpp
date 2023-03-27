//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
long long int f(long long int n,long long int num)
{
    if(n<0) return 0;
    if(n==0) return 1;
    
    if(num==3)
        return f(n-3,3)+f(n-5,5)+f(n-10,10);
    if(num==5)
        return f(n-5,5)+f(n-10,10);
    if(num==10)
        return f(n-10,10);
}
long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	
	return f(n,3);
	
	return table[n];
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends