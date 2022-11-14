//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int f(int i,string& S,string& W,bool visited[])
    {
        int k=0;
        for(int j=0;j<S.length();j++)
        {
            if(!visited[j] && S[j]==W[k])
            {
                visited[j]=true;
                k++;
            }
        }
        return k==W.length();
    }
    int numberOfSubsequences(string S, string W){
        bool visited[S.length()]={0};
        int count=0;
        for(int i=0;i<S.length();i++)
        {
            if(!visited[i] && S[i]==W[0])
            if(f(i,S,W,visited)) count++;
        }
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
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends