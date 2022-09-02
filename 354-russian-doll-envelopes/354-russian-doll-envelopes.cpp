class Solution {
public:
    // Recursion
    // int f(int ind,vector<vector<int>>& envelopes,int n,int prev)
    // {
    //     if(ind==n)
    //         return 0;
    //     int nottake=f(ind+1,envelopes,n,prev);
    //     int take=INT_MIN;
    //     if(prev==-1 || (envelopes[ind][0]>envelopes[prev][0] && envelopes[ind][1]>envelopes[prev][1]))
    //         take=1+f(ind+1,envelopes,n,ind);
    //     return max(take,nottake);
    // }
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     sort(envelopes.begin(),envelopes.end());
    //     int n=envelopes.size();
    //     return f(0,envelopes,n,-1);
    // }
    
    // Memoization
    // int f(int ind,vector<vector<int>>& envelopes,int n,int prev,vector<vector<int>>& dp)
    // {
    //     if(ind==n)
    //         return 0;
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int nottake=f(ind+1,envelopes,n,prev,dp);
    //     int take=INT_MIN;
    //     if(prev==-1 || (envelopes[ind][0]>envelopes[prev][0] && envelopes[ind][1]>envelopes[prev][1]))
    //         take=1+f(ind+1,envelopes,n,ind,dp);
    //     return dp[ind][prev+1]=max(take,nottake);
    // }
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     sort(envelopes.begin(),envelopes.end());
    //     int n=envelopes.size();
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return f(0,envelopes,n,-1,dp);
    // }
    // Tabulation
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     sort(envelopes.begin(),envelopes.end());
    //     int n=envelopes.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+2,0));
    //     for(int ind=n-1;ind>=0;ind--)
    //     {
    //         for(int prev=ind-1;prev>=-1;prev--)
    //         {
    //             int nottake=dp[ind+1][prev+1];
    //             int take=INT_MIN;
    //             if(prev==-1 || (envelopes[ind][0]>envelopes[prev][0] && envelopes[ind][1]>envelopes[prev][1]) )
    //             {
    //                 take=1+dp[ind+1][ind+1];
    //             }
    //             dp[ind][prev+1]=max(take,nottake);
    //         }
    //     }
    //     return dp[0][0];
    // }
   static bool cmp(vector<int>& first,vector<int>& second) 
        {
            if(first[0]<second[0]) return true;
            if(first[0]==second[0] && first[1]>second[1])
                return true;
            return false;
        }
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        vector<int> dp;
        
        sort(envelopes.begin(),envelopes.end(),cmp); // sorting heights in increasing order already
        // so we work upon only widths 
        dp.push_back(envelopes[0][1]);
        int n=envelopes.size();
        for(int i=1;i<n;i++)
        {
            if(envelopes[i][1]>dp.back())
            {
                dp.push_back(envelopes[i][1]);
            }
            else
            {
                int ind=lower_bound(dp.begin(),dp.end(),envelopes[i][1])-dp.begin();
                dp[ind]=envelopes[i][1];
            }
        }
        return dp.size();
    }
};