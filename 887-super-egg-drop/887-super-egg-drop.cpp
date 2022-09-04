class Solution {
public:
    int f(int n,int k,vector<vector<int>>& dp)
    {
        if(n==0 || n==1) return n;
        if(k==1) return n;
        
        if(dp[n][k]!=-1) return dp[n][k];
       
        int minmove=1e9;
        int start=1,end=n;
        while(start<=end)
        {
            int mid=(start+end)/2;
            int eggnotbreak=f(n-mid,k,dp);
            int eggbreak=f(mid-1,k-1,dp);
            minmove=min(minmove,1+max(eggbreak,eggnotbreak));
            if(eggbreak<eggnotbreak) // since we need more value in worst case
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return dp[n][k]=minmove;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f(n,k,dp);
    }
};