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
    int palindromicPartition(string str)
    {
        int n=str.length();
        vector<int> dp(n+1,0);
        dp[n]=-1;
        for(int ind=n-1;ind>=0;ind--)
        {
            int mini=1e9;
            string curr="";
            for(int i=ind;i<n;i++)
            {
                curr.push_back(str[i]);
                if(palindrome(curr)) mini=min(mini,1+dp[i+1]); 
            }
           dp[ind]=mini;
        }
        return dp[0];
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