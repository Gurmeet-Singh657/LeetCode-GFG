class Solution {
public:
    bool f(int ind,string& s,unordered_set<string>& st,int maxlen,vector<int>& dp)
    {
        if(ind==s.size())
            return true;
        if(dp[ind]!=-1) return dp[ind];
        string temp="";
        for(int i=ind;i<ind+maxlen && i<s.size();i++)
        {
            temp+=s[i];
            if(st.find(temp)!=st.end())
                if(f(i+1,s,st,maxlen,dp))
                    return dp[ind]=true;
        }
        return dp[ind]=false;
    }
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
        vector<int> dp(n,-1);
        return f(0,s,st,maxlen,dp);
    }
};