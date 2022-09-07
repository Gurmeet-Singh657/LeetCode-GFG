class Solution {
public:
        bool f(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp)
        {
            if (i + j == s3.length())
                return i == s1.length() && j == s2.length();
            if (dp[i][j] != -1)
                return dp[i][j];
            if (i < s1.length() && s1[i] == s3[i + j])
            {
                bool curr1 = f(s1, s2, s3, i + 1, j, dp);
                if (curr1 == true)
                    return dp[i][j] = true;
            }
            if (j < s2.length() && s2[j] == s3[i + j])
            {
                bool curr2 = f(s1, s2, s3, i, j + 1, dp);
                if (curr2 == true)
                    return dp[i][j] = true;
            }
            return dp[i][j] = false;
        }
        bool isInterleave(string s1, string s2, string s3)
        {
            if (s1.length() + s2.length() != s3.length())
                return false;
            int n = s1.length();
            int m = s2.length();
            int total = s3.length();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
            return f(s1, s2, s3, 0, 0, dp);
        }
};