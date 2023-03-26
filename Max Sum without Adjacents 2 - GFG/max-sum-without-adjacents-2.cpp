//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int findMaxSum(vector<int>& a){
      int n=a.size();
      vector<int> dp(n+3,0);
      for(int ind=n-1;ind>=0;ind--)
      {
          int nottake=dp[ind+1];
          int take1=a[ind]+dp[ind+2];
          int take2=-1e9;
          if(ind+1<n)
              take2=a[ind]+a[ind+1]+dp[ind+3];
          dp[ind]=max(max(take1,take2),nottake);
      }
      return dp[0];
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