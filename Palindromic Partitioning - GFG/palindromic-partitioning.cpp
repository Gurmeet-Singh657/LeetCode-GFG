//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool palindrome(string& str)
    {
        int i=0,j=str.length()-1;
        while(i<=j)
        {
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int ind,string& str,vector<int>& dp)
    {
        if(ind==str.length()) return -1;
        string curr="";
        int mini=1e9;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<str.length();i++)
        {
            curr.push_back(str[i]);
            if(palindrome(curr)) mini=min(mini,1+f(i+1,str,dp)); 
        }
        return dp[ind]=mini;
    }
    int palindromicPartition(string str)
    {
        int n=str.length();
        vector<int> dp(n,-1);
        return f(0,str,dp);
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