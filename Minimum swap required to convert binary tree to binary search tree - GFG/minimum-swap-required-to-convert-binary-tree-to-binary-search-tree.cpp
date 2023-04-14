//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    void MakeBST(int ind,vector<int>& A,vector<int>& C,int n)
    {
        if(ind>=n) return;
        MakeBST(2*ind+1,A,C,n);
        C.push_back(A[ind]);
        MakeBST(2*ind+2,A,C,n);
    }
    int minSwaps(vector<int>&A, int n){
        vector<int> C;
        MakeBST(0,A,C,n);
        vector<pair<int,int>> B;
        for(int i=0;i<n;i++) B.push_back({C[i],i});
        sort(B.begin(),B.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            int currval=B[i].first;
            int actualpos=B[i].second;
            int currpos=i;
            if(actualpos!=currpos)
            swap(B[actualpos],B[currpos]),i--,count++;
        }
        return count;
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends