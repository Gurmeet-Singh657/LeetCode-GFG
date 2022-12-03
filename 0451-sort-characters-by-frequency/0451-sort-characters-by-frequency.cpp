class Solution {
public:
    static bool cmp(pair<char,int>& p1,pair<char,int>& p2)
    {
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        vector<pair<char,int>> v;
        map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto it:mp)
        {
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        string curr="";
        for(auto it:v)
        {
            for(int i=0;i<it.second;i++)
            {
                curr+=it.first;
            }
        }
        return curr;
    }
};