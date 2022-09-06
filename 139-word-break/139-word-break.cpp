class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int maxlen=0;
        for(int i=0;i<wordDict.size();i++)
        {
            st.insert(wordDict[i]);
            int currsize=wordDict[i].length();
            maxlen=max(maxlen,currsize);
        }
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int ind=n-1;ind>=0;ind--)
        {
            string temp="";
            for(int i=ind;i<ind+maxlen && i<s.size();i++)
            {
                temp+=s[i];
                if(st.find(temp)!=st.end())
                    if(dp[i+1])
                        dp[ind]=true;
            }
        }
        return dp[0];
    }
};