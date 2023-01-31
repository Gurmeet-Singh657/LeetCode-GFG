//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int count=0;
    bool DFS(int node,vector<int> adj[],bool visited[])
    {
        bool selected=false;
        visited[node]=true;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                // if from bottom node is not selected -> select now
                if(!DFS(it,adj,visited))
                {
                    selected=true;
                }
            }
        }
        if(selected) count++;
        return selected;
    }
    int countVertex(int N, vector<vector<int>>edges){
        bool visited[N+1]={0};
        vector<int> adj[N+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        DFS(1,adj,visited);
        return count;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends