//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        int suffix[N];
        suffix[N-1]=A[N-1];
        for(int i=N-2;i>=0;i--)
        {
            suffix[i]=min(suffix[i+1],A[i]);
        }
        int maxi=A[0];
        int count=0;
        for(int i=1;i<N;i++)
        {
            if(maxi+suffix[i]>=K) count++;
            maxi=max(maxi,A[i]);
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends