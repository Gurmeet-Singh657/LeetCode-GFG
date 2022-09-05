class Solution {
public:
    int mxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen)
    {
        int n=nums.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(i<firstLen)
            {
                sum+=nums[i];
                left[i]=sum;
            }
            else
            {
                sum+=nums[i]-nums[i-firstLen];
                left[i]=max(left[i-1],sum);
            }
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i+secondLen>=n)
            {
                sum+=nums[i];
                right[i]=sum;
            }
            else
            {
                sum+=nums[i]-nums[i+secondLen];
                right[i]=max(right[i+1],sum);
            }
        }
        int maxsum=0;
        for(int i=firstLen-1;i<n-secondLen;i++)
        {
            maxsum=max(maxsum,left[i]+right[i+1]);
        }
        return maxsum;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        return max(mxSumTwoNoOverlap(nums,firstLen,secondLen),mxSumTwoNoOverlap(nums,secondLen,firstLen));
    }
};