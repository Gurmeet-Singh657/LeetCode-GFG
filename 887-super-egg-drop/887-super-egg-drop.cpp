class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int floor=1;floor<=n;floor++)
        {
            for(int egg=1;egg<=k;egg++)
            {
                if(egg==1) dp[floor][egg]=floor;
                else if(floor==1) dp[floor][egg]=1;
                else
                {
                    int minmove=1e9;
                    int start=1,end=floor;
                    while(start<=end)
                    {
                        int mid=(start+end)/2;
                        int eggnotbreak=dp[floor-mid][egg];
                        int eggbreak=dp[mid-1][egg-1];
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
                    dp[floor][egg]=minmove;
                }
                
            }
        }
        return dp[n][k];
    }
};