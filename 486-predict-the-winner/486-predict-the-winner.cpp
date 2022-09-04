class Solution {
public:
    int f(vector<int>& nums,int start,int end)
    {
        if(start==end) return nums[start];
        int ithtake=nums[start]-f(nums,start+1,end);
        int jthtake=nums[end]-f(nums,start,end-1);
        return max(ithtake,jthtake);
    }
    bool PredictTheWinner(vector<int>& nums) {
        return f(nums,0,nums.size()-1)>=0;
    }
};