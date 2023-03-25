//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int f(int i,int j,int n,string& str1,string& str2,vector<vector<int>>& dp)
	    {
	        if(i==n || j==n) return 0;
	        if(dp[i][j]!=-1) return dp[i][j];
	        int ans=1e9;
	        if(str1[i]==str2[j] && i!=j)
	           ans=1+f(i+1,j+1,n,str1,str2,dp);
	        else
	           ans=max(f(i+1,j,n,str1,str2,dp),f(i,j+1,n,str1,str2,dp));
	       return dp[i][j]=ans;
	    }
		int LongestRepeatingSubsequence(string str){
		    string str1=str;
		    string str2=str;
		    int n=str.length();
		    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
		    for(int i=n-1;i>=0;i--)
		    {
		        for(int j=n-1;j>=0;j--)
		        {
		            int ans=1e9;
        	        if(str1[i]==str2[j] && i!=j)
        	           ans=1+dp[i+1][j+1];
        	        else
        	           ans=max(dp[i+1][j],dp[i][j+1]);
        	       dp[i][j]=ans;
		        }
		    }
		    return dp[0][0];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends