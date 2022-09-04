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
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // when i's are exhausted then all js will be taken
        for(int j=0;j<m;j++)
        {
            dp[n][j]=findascii(s2,j);
        }
        // when js are exhausted then all is will be taken
        for(int i=0;i<n;i++)
        {
            dp[i][m]=findascii(s1,i);
        }
        // when both are exhausted , so 0 is the answer
        dp[n][m]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(s1[i]==s2[j])
                    dp[i][j]=dp[i+1][j+1];
                else
                    dp[i][j]=min((int)(s1[i])+dp[i+1][j],(int)(s2[j])+dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};