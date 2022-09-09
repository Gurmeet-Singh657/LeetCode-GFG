class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,vector<int>> bus;
        bool stops[100000]={0};
        bool nos[501]={0};
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                bus[routes[i][j]].push_back(i);
            }
        }
        queue<int> q;
        q.push(source);
        stops[source]=true;
        int level=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                auto it=q.front();
                q.pop();
                if(it==target)
                    return level;
                for(auto val:bus[it])
                {
                    if(nos[val])
                        continue;
                    vector<int> curr=routes[val];
                    for(int i=0;i<curr.size();i++)
                    {
                        if(stops[curr[i]])
                            continue;
                        q.push(curr[i]);
                        stops[curr[i]]=true;
                    }
                    nos[val]=true;
                }
            }
            level++;
        }
        return -1;
    }
};