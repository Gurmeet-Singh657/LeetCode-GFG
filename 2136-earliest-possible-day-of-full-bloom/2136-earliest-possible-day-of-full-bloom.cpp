class Solution {
public:
    static bool cmp(pair<int,int>& p1,pair<int,int>& p2)
    {
        return p1.second>p2.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> pgb;
        for(int i=0;i<plantTime.size();i++)
        {
            pgb.push_back({plantTime[i],growTime[i]});
        }
        sort(pgb.begin(),pgb.end(),cmp);
        int maximumval=0;
        int prev=0;
        for(int i=0;i<pgb.size();i++)
        {
            prev+=pgb[i].first;
            maximumval=max(maximumval,prev+pgb[i].second);
        }
        return maximumval;
    }
};