//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	class node{
	    public:
	    int u;
	    int v;
	    int wt;
	};
	static bool cmp(node a,node b)
	{
	    return a.wt<b.wt;
	}
	int parent[1001],rank[1001];
	int findParent(int u)
	{
	    if(parent[u]==u) return u;
	    return parent[u]=findParent(parent[u]);
	}
	void Union(int u,int v)
	{
	    u=findParent(u);
	    v=findParent(v);
	    if(rank[u]==rank[v])
	    {
	        rank[v]++;
	        parent[u]=v;
	    }
	    else if(rank[u]<rank[v])
	    {
	        parent[u]=v;
	    }
	    else
	    {
	        parent[v]=u;
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<node> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int adj_node=it[0],adj_wt=it[1];
                edges.push_back({i,adj_node,adj_wt});
            }
        }
        for(int i=0;i<=1000;i++) parent[i]=i,rank[i]=0;
        sort(edges.begin(),edges.end(),cmp);
        int count=0;
        int cost=0;
        for(auto it:edges)
        {
            if(findParent(it.u)!=findParent(it.v))
            {
                cost+=it.wt;
                Union(it.u,it.v);
            }
        }
        return cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends