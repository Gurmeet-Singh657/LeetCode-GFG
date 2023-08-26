//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<vector<int>> ans;
        vector<pair<int,int>> adj(n+1);
        for(int i=0;i<=n;i++) adj[i]={-1,0};
        vector<bool> Incoming(n+1,0);
        for(int i=0;i<p;i++)
        {
            int u=a[i];
            int v=b[i];
            int wt=d[i];
            adj[u]={v,wt};
            Incoming[v]=true;
        }
        for(int i=1;i<=n;i++)
        {
            // This means some edge is going out of it, it must not be last node
            if(Incoming[i]) continue;
            
            int firstNode=i;
            int lastNode=i;
            int minDiameter=1e9;
            int curr=i;
            while(adj[curr].first!=-1)
            {
                auto temp=adj[curr];
                int adjNode=temp.first;
                int dist=temp.second;
                minDiameter=min(minDiameter,dist);
                curr=adjNode;
                lastNode=curr;
            }
            if(firstNode!=lastNode)
                ans.push_back({firstNode,lastNode,minDiameter});
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends