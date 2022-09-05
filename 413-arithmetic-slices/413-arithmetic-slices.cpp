class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=2) return 0;
        int n=nums.size();
        vector<int> dp(n,0);
        if(nums[2]-nums[1]==nums[1]-nums[0])
            dp[2]=1;
        for(int i=3;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                dp[i]=1+dp[i-1];
        }
        int sum=0;
        for(int i=2;i<n;i++)
        {
            sum+=dp[i];
        }
        return sum;
    }
};