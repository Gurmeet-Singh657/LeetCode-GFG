//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int f(int ind,vector<int>& a,int n,vector<int>& dp)
  {
      if(ind>=n) return 0;
      if(dp[ind]!=-1) return dp[ind];
      int nottake=f(ind+1,a,n,dp);
      int take1=a[ind]+f(ind+2,a,n,dp);
      int take2=-1e9;
      if(ind+1<n)
          take2=a[ind]+a[ind+1]+f(ind+3,a,n,dp);
      return dp[ind]=max(max(take1,take2),nottake);
  }
  int findMaxSum(vector<int>& a){
      int n=a.size();
      vector<int> dp(n,-1);
      return f(0,a,n,dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends