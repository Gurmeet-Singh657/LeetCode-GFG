class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        
        
        int countstar=0;
        int countele=0;
        for(int j=p.length()-1;j>=0;j--)
        {
            if(p[j]=='*')
                countstar++;
            else
                countele++;
            dp[n][j]=(countstar>=countele);
        }
        dp[n][m]=1;
        
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