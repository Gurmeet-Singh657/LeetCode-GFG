class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(int i=0;i<t.length();i++)
        {
            mp[t[i]]++;
        }
        map<char,int> smp;
        int count=0;
        int start=0;
        int mini=INT_MAX;
        int startindex=-1;
        for(int i=0;i<s.length();i++)
        {
            smp[s[i]]++;
            if(smp[s[i]]<=mp[s[i]])
                count++;
            if(count==t.length())
            {
                while(smp[s[start]]>mp[s[start]])
                {
                    smp[s[start]]--;
                    start++;
                }
                 if(i-start+1<mini)
                {
                    mini=i-start+1;
                    startindex=start;
                }
            }
           
        }
        if(startindex==-1) return "";
        return s.substr(startindex,mini);
    }
};