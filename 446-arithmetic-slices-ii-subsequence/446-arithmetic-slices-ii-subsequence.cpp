#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int finalans=0;
        vector<unordered_map<ll,int>> dp(n);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ll commondiff=1LL*nums[j]-1LL*nums[i];
                if(commondiff<=INT_MIN || commondiff>=INT_MAX)
                    continue;
                int ans=0;
                if(dp[j].find(commondiff)!=dp[j].end())
                    ans+=dp[j][commondiff];
                dp[i][commondiff]+=ans+1;
                finalans+=ans;
            }
        }
        return finalans;
    }
};