//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        stack<int> st;
        int maxlen=0;
        st.push(-1);
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(') st.push(i);
            else 
            {
                st.pop();
                if(st.empty()) st.push(i);
                else
                {
                    maxlen=max(maxlen,i-st.top());
                }
            }
        }
        return maxlen;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends