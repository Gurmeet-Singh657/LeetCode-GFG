class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        dp[n][m]=1;
        for(int j=p.length()-2;j>=0;j--)
        {
            if(j<p.length() && p[j+1]=='*' && dp[n][j+2]==true)
            {
                dp[n][j]=true;
            }
            else // *p* case never comes so it doesn't matter whatever is marked but if dp[j+2]==false then
                // it is never possible to get answer
            {
                dp[n][j]=false;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(j<m-1 && p[j+1]=='*')
                {
                    if(s[i]==p[j] || p[j]=='.')
                        dp[i][j]= (dp[i+1][j] | dp[i][j+2]);
                    else
                        dp[i][j]=dp[i][j+2];
                }
                else if(s[i]==p[j] || p[j]=='.')
                {
                    dp[i][j]=dp[i+1][j+1];
                }
                else
                    dp[i][j]=false;
            }
        }
        
        return dp[0][0];
    }
};