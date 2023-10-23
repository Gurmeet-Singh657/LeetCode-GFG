//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool checkPalindrome(int i,int j,string& str)
    {
        while(i<=j)
        {
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int ind,string& str,vector<int>& dp)
    {
        if(ind==str.length()) return -1;
        
        if(dp[ind]!=-1) return dp[ind];
        int mini=1e9;
        string curr="";
        for(int j=ind;j<str.length();j++)
        {
            curr.push_back(str[j]);
            if(checkPalindrome(ind,j,str))
            {
                int curr=1+solve(j+1,str,dp);
                mini=min(mini,curr);
            }
        }
        return dp[ind]=mini;
    }
    int palindromicPartition(string str)
    {
        int n=str.length();
        vector<int> dp(n+1,-1);
        return solve(0,str,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends