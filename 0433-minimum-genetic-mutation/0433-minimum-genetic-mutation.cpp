class Solution {
public:
    int FindMutation(string& start,string& end,unordered_map<string,bool>& visited)
    {
        if(start==end)
            return 0;
        int mini=1e9;
        for(auto it:visited)
        {
            if(it.second==false)
            {
                string curr=it.first;
                int countdis=0;
                for(int j=0;j<curr.length();j++)
                {
                    if(curr[j]!=start[j])
                        countdis++;
                }
                if(countdis==1)
                {
                    visited[it.first]=true;
                    mini=min(mini,1+FindMutation(curr,end,visited));
                    visited[it.first]=false; ;
                }
            }
        }
        return mini;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,bool> visited;
        for(int i=0;i<bank.size();i++)
        {
            visited.insert({bank[i],false});
        }
        if(visited.find(end)==visited.end()) return -1;
        int ans=FindMutation(start,end,visited);
        return ans>=1e9?-1:ans;
    }
};