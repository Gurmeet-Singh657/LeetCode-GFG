class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0) return {};
        multiset<int> st1;
        sort(changed.begin(),changed.end()); // ensuring the single number comes before double 
        vector<int> ans;
        for(int i=0;i<changed.size();i++)
        {
            if(changed[i]%2==0 && !st1.empty() && st1.find(changed[i]/2)!=st1.end())
            {
                auto it=st1.find(changed[i]/2);
                st1.erase(it);
            }
            else {
                ans.push_back(changed[i]);
                st1.insert(changed[i]);
            }
        }
        if(st1.size()!=0)
            ans.clear();
        return ans;
        
    }
};