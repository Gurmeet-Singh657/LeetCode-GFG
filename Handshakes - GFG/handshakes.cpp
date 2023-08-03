//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int f(int N)
    {
        vector<int> dp(N+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=N;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i]+=(dp[j]*dp[i-j-1]);
            }
        }
        return dp[N];
    }
    int count(int N){
        if(N%2) return 0;
        return f(N/2);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends