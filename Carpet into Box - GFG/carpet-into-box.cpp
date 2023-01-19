//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int moves=0;
        while(max(C,D)<max(A,B))
        {
            if(A>=B) A/=2;
            else B/=2;
            moves++;
        }
        while(min(C,D)<min(A,B))
        {
            if(A<=B) A/=2;
            else B/=2;
            moves++;
        }
        return moves;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends