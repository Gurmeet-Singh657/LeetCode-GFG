class Solution {
public:
    void DFS(vector<int> adj[],int i,bool visited[])
    {
        visited[i]=true;
        for(auto it:adj[i])
        {
            if(!visited[it])
                DFS(adj,it,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        bool visited[201]={0};
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                DFS(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};