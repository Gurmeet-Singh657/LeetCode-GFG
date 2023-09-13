//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(N*9<S) return "-1";
        if(S==0)
        {
            if(N==1) return "0";
            return "-1";
        }
        string ans;
        while(N--)
        {
            char ch=(min(9,S)+'0');
            ans.push_back(ch);
            S-=min(9,S);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends