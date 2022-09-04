class Solution {
public:
    int f(vector<int>& nums,int start,int end)
    {
        if(start>end) return 0;
        if(start==end) return nums[start];
        int ithtake=nums[start]+min(f(nums,start+1,end-1),f(nums,start+2,end));
        int jthtake=nums[end]+min(f(nums,start+1,end-1),f(nums,start,end-2));
        return max(ithtake,jthtake);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int player1score=f(nums,0,nums.size()-1);
        int totalscore=accumulate(nums.begin(),nums.end(),0);
        return player1score>=totalscore-player1score;
    }
};