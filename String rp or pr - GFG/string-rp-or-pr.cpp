//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      stack<char> st;
      int n=S.length();
      long long ans=0;
      for(int i=0;i<n;i++)
      {
          if(S[i]!='r' && S[i]!='p')
          {
              if(!st.empty())
              {
                  char ch=st.top();
                  int countr=0,countp=0;
                  while(!st.empty())
                  {
                      if(st.top()=='r') countr++;
                      else countp++;
                      st.pop();
                  }
                  if(ch=='r') ans+=X*min(countr,countp);
                  if(ch=='p') ans+=Y*min(countr,countp);
              }
              continue;
          }
          
          if(st.empty()) st.push(S[i]);
          else if(X>=Y) // removing pr is better than removing rp
          {
              if(st.top()=='p' && S[i]=='r')
              {
                  ans+=X;
                  st.pop();
              }
              else
              {
                  st.push(S[i]);
              }
          }
          else  // X>Y -> removing rp is better than removing pr
          {
              if(st.top()=='r' && S[i]=='p')
              {
                  ans+=Y;
                  st.pop();
              }
              else
              {
                  st.push(S[i]);
              }
          }
      }
      if(!st.empty())
      {
          char ch=st.top();
          int countr=0,countp=0;
          while(!st.empty())
          {
              if(st.top()=='r') countr++;
              else countp++;
              st.pop();
          }
          if(ch=='r') ans+=X*min(countr,countp);
          if(ch=='p') ans+=Y*min(countr,countp);
      }
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends