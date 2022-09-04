#define ll long long int
class Solution {
public:
    struct cmp{
        bool operator()(pair<ll,ll>& p1, pair<ll,ll>& p2)
        {
            if(p1.first>p2.first) return true;
            if(p1.first==p2.first && p1.second>p2.second) return true;
            return false;
        }
    };
    
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp> pq;
        map<ll,ll> mp;
        priority_queue<ll,vector<ll>,greater<ll>> epq;
        for(int i=0;i<n;i++)
            epq.push(i);
        for(int i=0;i<meetings.size();i++)
        {
                while(!pq.empty() && meetings[i][0]>=pq.top().first)
                {
                    epq.push(pq.top().second);
                    pq.pop();  
                }
                if(epq.size()==0)
                {
                    ll first=meetings[i][0];
                    ll second=meetings[i][1];
                    auto it=pq.top();
                    pq.pop();
                    ll diff=it.first-first;
                    second+=diff;
                    pq.push({second,it.second});
                    mp[it.second]++;
                }
                else
                {
                    pq.push({meetings[i][1],epq.top()});
                    mp[epq.top()]++;
                    epq.pop();
                }
        }
        ll minindex=INT_MAX;
        ll maxi=0;
        for(auto it:mp)
        {
            if(it.second>maxi)
            {
                maxi=it.second;
                minindex=it.first;
            }
            else if(it.second==maxi)
            {
                minindex=min(minindex,it.second);
            }
        }
        return minindex;
    }
};