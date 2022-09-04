class Solution {
public:
    int findascii(string& s,int k)
    {
        int curr=0;
        for(int i=k;i<s.length();i++)
        {
            curr+=(int)(s[i]);
        }
        return curr;
    }
    int f(string& s,string& t,int i,int j,vector<vector<int>>& dp)
    {
        if(i==s.length() || j==t.length())
        {
            return findascii(s,i)+findascii(t,j);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=f(s,t,i+1,j+1,dp);
        else
        {
            return dp[i][j]=min((int)s[i]+f(s,t,i+1,j,dp),(int)t[j]+f(s,t,i,j+1,dp));
        }   
        return -1;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(s1,s2,0,0,dp);
    }
};