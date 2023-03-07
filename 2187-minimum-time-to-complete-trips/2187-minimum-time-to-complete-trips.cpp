class Solution {
public:
    #define ll long long int
    bool check(vector<int>& time,ll mid,int tT)
    {
        ll sum=0;
        for(auto it:time) sum+=(mid/it);
        return sum>=tT;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll start=1,end=1e14;
        ll ans=-1;
        while(start<=end)
        {
            ll mid=(start+end)/2;
            if(check(time,mid,totalTrips))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};