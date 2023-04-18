//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        int freq[N+1]={0};
        for(int i=0;i<N;i++)
        {
            if(S[i]=='1')
            {
                int left=max(0,i-X);
                int right=min(N-1,i+X);
                freq[left]++;
                freq[right+1]--;
            }
        }
        for(int i=0;i<N;i++)
        {
            if(i>0)
            freq[i]+=freq[i-1];
            if(freq[i]==0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends