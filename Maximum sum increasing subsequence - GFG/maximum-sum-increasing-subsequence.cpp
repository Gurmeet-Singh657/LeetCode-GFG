//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> next(n+1,0);
	    
	    for(int i=0;i<=n;i++) next[i]=0;
	    
	    for(int ind=n-1;ind>=0;ind--)
	    {
	        vector<int> curr(n,0);
	        for(int prev=-1;prev<ind;prev++)
	        {
	            int notTake=next[prev+1];
        	    int take=-1e9;
        	    if(prev==-1 || arr[ind]>arr[prev])
        	        take=arr[ind]+next[ind+1];
        	    curr[prev+1]=max(take,notTake);
	        }
	        next=curr;
	    }
	    return next[0];
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends