class Solution {
public:
    bool f(string& s,string& p,int i,int j,vector<vector<int>>& dp)
    {
        if(i==s.length())
        {
            if(j==p.length()) return true;
            int countstar=0,countele=0;
            for(int k=p.length()-1;k>=j;k--)
            {
                if(p[k]=='*')
                    countstar++;
                else
                {
                    countele++;
                    if(countstar<countele)
                        return false;
                }
            }
            return true;
        }
        if(j==p.length())
            return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j+1]=='*')
        {
            if(s[i]==p[j] || p[j]=='.')
                return dp[i][j]= (f(s,p,i+1,j,dp) | f(s,p,i,j+2,dp));
            else
                return dp[i][j]=f(s,p,i,j+2,dp);
        }
        else if(s[i]==p[j] || p[j]=='.')
            return dp[i][j]=f(s,p,i+1,j+1,dp);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return f(s,p,0,0,dp);
    }
};