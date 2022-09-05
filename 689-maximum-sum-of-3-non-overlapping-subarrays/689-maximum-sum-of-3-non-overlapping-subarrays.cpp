class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        vector<int> prefixsum(n,0);
        vector<int> leftsum(n,0);
        vector<int> rightsum(n,0);
        prefixsum[0]=nums[0];
        for(int i=1;i<n;i++)
            prefixsum[i]=nums[i]+prefixsum[i-1];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(i<k)
            {
                sum+=nums[i];
                leftsum[i]=sum;
            }
            else
            {
                sum+=nums[i]-nums[i-k];
                leftsum[i]=max(leftsum[i-1],sum);
            }
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i+k>=n)
            {
                sum+=nums[i];
                rightsum[i]=sum;
            }
            else
            {
                sum+=nums[i]-nums[i+k];
                rightsum[i]=max(rightsum[i+1],sum);
            }
        }
        int msa=-1;
        int lsa=-1;
        int rsa=-1;
        int lsum=0;
        int rsum=0;
        int maxsum=0;
        for(int i=k;i<=n-2*k;i++)
        {
            if(leftsum[i-1]+rightsum[i+k]+prefixsum[i+k-1]-prefixsum[i-1]>maxsum)
            {
                maxsum=leftsum[i-1]+rightsum[i+k]+prefixsum[i+k-1]-prefixsum[i-1];
                lsum=leftsum[i-1];
                rsum=rightsum[i+k];
                msa=i;
            }
        }
        for(int i=k-1;i<msa;i++)
        {
            if(lsum==prefixsum[i]-(i-k>=0?prefixsum[i-k]:0))
            {
                ans.push_back(i-k+1);
                break;
            }
        }
        ans.push_back(msa);
        for(int i=msa+2*k-1;i<n;i++)
        {
            if(rsum==prefixsum[i]-(i-k>=0?prefixsum[i-k]:0))
            {
                ans.push_back(i-k+1);
                break;
            }
        }
        return ans;
    }
};