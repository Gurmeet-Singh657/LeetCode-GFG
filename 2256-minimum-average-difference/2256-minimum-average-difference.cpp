class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),0);
        nums.push_back(0);
        vector<int> pre(n+2,0);
        vector<int> suffix(n+2,0);
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=nums[i];
            pre[i]=(sum/i);
        }
        sum=0;
        for(int i=n;i>=1;i--)
        {
            sum+=nums[i];
            suffix[i]=(sum/(n-i+1));
        }
        int mini=INT_MAX;
        int minindex=-1;
        for(int i=1;i<=n;i++)
        {
            int curr=abs(pre[i]-suffix[i+1]);
            if(curr<mini)
            {
                mini=curr;
                minindex=i-1;
            }
        }
        return minindex;
    }
};