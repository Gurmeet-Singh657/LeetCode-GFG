class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int end=0;
        int n=nums.size();
        int sum=0;
        map<int,int> mp;
        mp[0]=-1;
        while(end<n)
        {
            sum+=nums[end];
            sum%=k;
            if(mp.find(sum)!=mp.end())
            {
                if(end-mp[sum]>1)
                    return true;
            }
            else
            {
                mp.insert({sum,end});
            }
            end++;
        }
        return false;
    }
};