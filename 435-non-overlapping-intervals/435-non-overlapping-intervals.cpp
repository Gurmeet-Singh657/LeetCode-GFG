class Solution {
public:
    // Recursion
    // int f(vector<vector<int>>& intervals,int ind,int n,int prev)
    // {
    //     if(ind==n)
    //         return 0;
    //     int nottake=f(intervals,ind+1,n,prev);
    //     int take=INT_MIN;
    //     if(prev==-1 || intervals[prev][1]<=intervals[ind][0])
    //         take=1+f(intervals,ind+1,n,ind);
    //     return max(take,nottake);
    // }
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(),intervals.end());
    //     return intervals.size()-f(intervals,0,intervals.size(),-1);
    // }
    // Memoization
    // int f(vector<vector<int>>& intervals,int ind,int n,int prev,vector<vector<int>>& dp)
    // {
    //     if(ind==n)
    //         return 0;
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int nottake=f(intervals,ind+1,n,prev,dp);
    //     int take=INT_MIN;
    //     if(prev==-1 || intervals[prev][1]<=intervals[ind][0])
    //         take=1+f(intervals,ind+1,n,ind,dp);
    //     return dp[ind][prev+1]=max(take,nottake);
    // }
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(),intervals.end());
    //     vector<vector<int>> dp(intervals.size(),vector<int>(intervals.size()+1,-1));
    //     return intervals.size()-f(intervals,0,intervals.size(),-1,dp);
    // }
    // Tabulation
    
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(),intervals.end());
    //     int n=intervals.size();
    //     vector<vector<int>> dp(intervals.size()+1,vector<int>(intervals.size()+1,0));
    //     for(int ind=n-1;ind>=0;ind--)
    //     {
    //         for(int prev=ind-1;prev>=-1;prev--)
    //         {
    //             int nottake=dp[ind+1][prev+1];
    //             int take=INT_MIN;
    //             if(prev==-1 || intervals[prev][1]<=intervals[ind][0])
    //                 take=1+dp[ind+1][ind+1];
    //             dp[ind][prev+1]=max(take,nottake);
    //         }
    //     }
    //     return intervals.size()-dp[0][0];
    // }
    
    // O(nlogn) solution
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int prev=0;
        int count=0;
        for(int start=1;start<n;start++)
        {
            if(intervals[prev][1]<=intervals[start][0]) // Non - overlapping case
            {
                prev=start;
            }
            else if(intervals[prev][1]<=intervals[start][1]) // Partial Overlapping 
            {
                count+=1;
            }
            else if(intervals[prev][1]>intervals[start][1]) // Containing whole
            {
                count+=1;
                prev=start;
            }
        }
        return count;
        
    }
};