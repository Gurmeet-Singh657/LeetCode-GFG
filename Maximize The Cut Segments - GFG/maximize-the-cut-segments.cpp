//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int f(int n,int x,int y,int z,vector<int>& dp)
    {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int takex=-1e5,takey=-1e5,takez=-1e5;
        if(n>=x)
            takex=1+f(n-x,x,y,z,dp);
        if(n>=y)
            takey=1+f(n-y,x,y,z,dp);
        if(n>=z)
            takez=1+f(n-z,x,y,z,dp);
        return dp[n]=max(takex,max(takey,takez));
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int takex=-1e5,takey=-1e5,takez=-1e5;
            if(i>=x)
                takex=1+f(i-x,x,y,z,dp);
            if(i>=y)
                takey=1+f(i-y,x,y,z,dp);
            if(i>=z)
                takez=1+f(i-z,x,y,z,dp);
            dp[i]=max(takex,max(takey,takez));
        }
        int ans=dp[n];
        if(ans<0) return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends