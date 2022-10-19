class Solution {
public:
    static bool cmp(pair<string, int>& a,pair<string, int>& b)
        {
            if(a.second==b.second && a.first<b.first)
                return true;
            else if(a.second>b.second)
                return true;
        return false;
        }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        priority_queue<pair<int,string>> pq;
        map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        vector<pair<string,int>> v;
        for(auto it:mp)
        {
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        vector<string> ans;
        for(auto it:v)
        {
            ans.push_back(it.first);
            k--;
            if(k==0) break;
        }
        return ans;
    }
};