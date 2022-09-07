class Solution {
public:
    int numSplits(string s) {
        int count=0;
        unordered_map<int,int> mp1;
        vector<int> pre(s.length());
        for(int i=0;i<s.length();i++)
        {
            mp1[s[i]]++;
            pre[i]=mp1.size();
        }
        int mycount=mp1.size();
        mp1[s[0]]--;
        if(mp1[s[0]]==0) mycount--;
        for(int i=1;i<s.size();i++)
        {
            if(mycount==pre[i-1])
                count++;
            mp1[s[i]]--;
            if(mp1[s[i]]==0)
                mycount--;
        }
        return count;
    }
};