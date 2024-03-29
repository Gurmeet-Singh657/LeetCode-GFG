//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    #define mod (int)(1e9+7)
    /*You are required to complete below method */
    long long int f(int i,int j,string& str,vector<vector<int>>& dp)
    {
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(str[i]==str[j])
            ans=(f(i+1,j,str,dp)%mod+f(i,j-1,str,dp)%mod+1)%mod;
        else
            ans=(f(i+1,j,str,dp)%mod+f(i,j-1,str,dp)%mod-f(i+1,j-1,str,dp)%mod+mod)%mod;
        return dp[i][j]=ans;
    }
    long long int  countPS(string str)
    {
        int n=str.length();
        vector<vector<long long int>> dp(n+1,vector<long long int>(n+1,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(str[i]==str[j])
                    dp[i][j]=(dp[i+1][j]+dp[i][j-1]+1)%mod;
                else
                    dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+mod)%mod;
            }
        }
       return dp[0][n-1];
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends