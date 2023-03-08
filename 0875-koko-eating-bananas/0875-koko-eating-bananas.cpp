class Solution {
public:
    #define ll long long int
    bool check(ll mid,vector<int>& piles,int h)
    {
        ll ans=0;
        for(auto it:piles)
        {
            if(it%mid==0) ans+=(it/mid);
            else ans+=(it/mid)+1;
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll start=1,end=*max_element(piles.begin(),piles.end());
        ll ans;
        while(start<=end)
        {
            ll mid=(start+end)/2;
            if(check(mid,piles,h))
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