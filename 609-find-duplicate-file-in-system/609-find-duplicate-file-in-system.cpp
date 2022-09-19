class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>> mp;
        for(int k=0;k<paths.size();k++)
        {
            string curr=paths[k];
            string rootdir="";
            string ans="";
            int i=0;
            while(i<paths[k].size() && paths[k][i]!=' ')
            {
                rootdir+=paths[k][i];
                i++;
            }
            i++;
            while(i<paths[k].size())
            {
                if(paths[k][i]=='(')
                {
                    string mapped="";
                    i++;
                    while(i<paths[k].size() && paths[k][i]!=')')
                    {
                        mapped.push_back(paths[k][i]);
                        i++;
                    }
                    i++;
                    mp[mapped].push_back(rootdir+"/"+ans);
                    ans="";
                    i++;
                }
                if(i<paths[k].size())
                ans+=paths[k][i];
                i++;
            }
        }
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            if(it.second.size()>1)
            {
                vector<string> currans;
                for(auto it1:it.second)
                {
                    currans.push_back(it1);
                }
                ans.push_back(currans);
            }
        }
        return ans;
    }
};