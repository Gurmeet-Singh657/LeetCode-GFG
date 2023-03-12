//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        long long ans=0;
        int mini=INT_MAX;
        long long count=0;
        
        for(int i=0;i<N;i++)
        {
            // rectangles
            // B[i] -> number of sticks available
            
            int rect_pair=B[i]/2;
            ans+=(2*rect_pair*A[i]);
            mini=min(mini,A[i]);
            count+=rect_pair;
        }
        if(count%2!=0) ans-=(2*mini);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends