class Solution {
public:
    // O(nlogn) solution
    static bool cmp(vector<int>& first,vector<int>& second)
    {
        return first[1]<second[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        int prev=0;
        int count=0;
        for(int start=1;start<n;start++)
        {
           if(intervals[start][0]<intervals[prev][1])
               count++;
            else
                prev=start;
        }
        return count;
        
    }
};