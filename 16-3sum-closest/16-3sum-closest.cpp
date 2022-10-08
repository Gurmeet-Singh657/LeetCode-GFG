class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++)
        {
            int start=i+1,end=n-1;
            while(start<end)
            {
                int sum=nums[i]+nums[start]+nums[end];
                if(abs(sum-target)<=abs(ans-target))
                    ans=sum;
                if(sum==target)
                    return target;
                else if(sum>target)
                     end--;
                else
                    start++;
            }
        }
        return ans;
    }
};