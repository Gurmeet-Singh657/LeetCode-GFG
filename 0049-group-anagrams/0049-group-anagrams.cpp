class Solution {
public:
    string SortStr(string& curr)
    {
        int counter[26]={0};
        for(auto it:curr)
        {
            counter[it-'a']++;
        }
        string finalstr="";
        for(int i=0;i<26;i++)
        {
            finalstr+=string(counter[i],i+'a');
        }
        return finalstr;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(auto it:strs)
        {
            string curr=it;
            // sort(it.begin(),it.end());
            string sortedstr=SortStr(it);
            mp[sortedstr].push_back(curr);
        }
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};