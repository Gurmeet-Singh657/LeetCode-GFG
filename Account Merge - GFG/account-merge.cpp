//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    class DisjointSet
    {
    public:
        vector<int> parent, rank, size;
    
    public:
        DisjointSet(int n)
        {
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int findParent(int u)
        {
            if (parent[u] == u)
                return u;
            return parent[u] = findParent(parent[u]);
        }
        void Union(int u, int v)
        {
            u = findParent(u);
            v = findParent(v);
            if (size[u] < size[v])
            {
                parent[u] = v;
                size[v] += size[u];
            }
            else
            {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                    mp[accounts[i][j]]=i;
                else
                {
                    ds.Union(i,mp[accounts[i][j]]);
                }
            }
        }
        vector<string> mergedmails[n];
        for(auto it:mp)
        {
            int upar=ds.findParent(it.second);
            mergedmails[upar].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(mergedmails[i].size()>0)
            {
                vector<string> curr;
                curr.push_back(accounts[i][0]);
                curr.insert(curr.end(),mergedmails[i].begin(),mergedmails[i].end());
                ans.push_back(curr);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends