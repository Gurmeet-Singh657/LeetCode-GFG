#define mod (int)(1e9+7)
class Solution {
public:
    long long f(int start,int end,string& s,vector<int>& prev,vector<int>& next,vector<vector<int>>& dp)
    {
        if(start>end)
            return 0;
        if(start==end)
            return 1;
        long long ans=0;
        if(dp[start][end]!=-1) return dp[start][end];
        if(s[start]!=s[end])
        {
            ans=(f(start+1,end,s,prev,next,dp)+f(start,end-1,s,prev,next,dp)-f(start+1,end-1,s,prev,next,dp)+mod)%mod;
        }
        else
        {
            int nxt=next[start];
            int prv=prev[end];
        
            if(nxt>prv)
            {
                ans=(2*f(start+1,end-1,s,prev,next,dp)+2)%mod;
            }
            else if(nxt==prv)
            {
                ans=(2*f(start+1,end-1,s,prev,next,dp)+1)%mod;
            }
            else
            {
                ans=(2*f(start+1,end-1,s,prev,next,dp)-f(nxt+1,prv-1,s,prev,next,dp)+mod)%mod;
            }
        } 
        return dp[start][end]=ans;
    }
    int countPalindromicSubsequences(string s) {
        // building next and previous array
        vector<int> prev(s.length(),-1);
        map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                prev[i]=mp[s[i]];
            }
                mp[s[i]]=i;   
        }
        mp.clear();
        vector<int> next(s.length(),-1);
        for(int i=s.length()-1;i>=0;i--)
        {
            if(mp.find(s[i])!=mp.end())
            {
                next[i]=mp[s[i]];
            }
            mp[s[i]]=i;
        }
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,s.length()-1,s,prev,next,dp);
    }
};