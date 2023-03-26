//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        vector<int> ahead(N+2,0),curr(N+2,0);
        for(int ind=N-1;ind>=0;ind--)
        {
            for(int prev=-1;prev<ind;prev++)
            {
                int nottake=ahead[prev+1];
                int take=-1e9;
                if(prev==-1 || abs(A[ind]-A[prev])==1)
                    take=1+ahead[ind+1];
                curr[prev+1]=max(take,nottake);
            }
            ahead=curr;
        }
        return ahead[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends