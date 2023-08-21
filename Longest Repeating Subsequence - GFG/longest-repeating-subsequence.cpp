//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int f(int i,int j,string& str,vector<vector<int>>& dp)
	    {
	        if(i==str.length() || j==str.length()) return 0;
	        if(dp[i][j]!=-1) return dp[i][j];
	        int ans=0;
	        if(i!=j && str[i]==str[j]) ans=1+f(i+1,j+1,str,dp);
	        else ans=max(f(i,j+1,str,dp),f(i+1,j,str,dp));
	        return dp[i][j]=ans;
	    }
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    vector<vector<int>> dp(n,vector<int>(n,-1));
		    return f(0,0,str,dp);
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