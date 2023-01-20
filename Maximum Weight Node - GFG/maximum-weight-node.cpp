//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      vector<int> adj(N,0);
      for(int i=0;i<N;i++)
      {
          if(Edge[i]!=-1)
            adj[Edge[i]]+=i;
      }
      int maxwt=0;
      int maxind=-1;
      for(int i=0;i<N;i++)
      {
          if(adj[i]>maxwt)
          {
              maxwt=adj[i];
              maxind=i;
          }
          else if(adj[i]==maxwt)
          {
              maxind=i;
          }
      }
      return maxind;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends