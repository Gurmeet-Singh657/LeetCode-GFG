class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<pair<int,int>>> v;
        for(int i=0;i<stones.size();i++)
        {
            int prev=-1;
            for(int j=0;j<v.size();j++)
            {
                for(auto it:v[j])
                {
                    if(it.first==stones[i][0] || it.second==stones[i][1])
                    {
                        if(prev==-1)
                        {
                            v[j].push_back({stones[i][0],stones[i][1]});
                            prev=j;
                            break;    
                        }
                        else
                        {
                            v[prev].insert(v[prev].end(),v[j].begin(),v[j].end());
                            v[prev].push_back({stones[i][0],stones[i][1]});
                            v.erase(v.begin()+j);
                            j--;
                            break;
                        }
                    }
                }
            }
            if(prev==-1)
            {
                vector<pair<int,int>> vcurr;
                vcurr.push_back({stones[i][0],stones[i][1]});
                v.push_back(vcurr);
            }
        }
        return stones.size()-v.size();
    }
};