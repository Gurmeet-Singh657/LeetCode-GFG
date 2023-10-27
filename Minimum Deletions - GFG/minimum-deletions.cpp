//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(int i,int j,string& s,string& t,vector<vector<int>>& dp)
    {
        if(i==s.length() || j==t.length()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans;
        if(s[i]==t[j])
        {
            ans=1+solve(i+1,j+1,s,t,dp);
        }
        else
        {
            ans=max(solve(i+1,j,s,t,dp),solve(i,j+1,s,t,dp));
        }
        return dp[i][j]=ans;
    }
    int minimumNumberOfDeletions(string S) {
        string revStr=S;
        reverse(revStr.begin(),revStr.end());
        int n=S.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return n-solve(0,0,S,revStr,dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends