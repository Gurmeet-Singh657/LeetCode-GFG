#define ll long long int
#define mod (int)(1e9+7)
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> curr;
        for(int i=0;i<n;i++)
        {
            curr.push_back({efficiency[i],speed[i]});
        }
        sort(curr.rbegin(),curr.rend());
        ll ans=INT_MIN;
        ll sum=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(curr[i].second);
            sum+=curr[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(sum*curr[i].first,ans);
        }
        return ans%mod;
    }
};