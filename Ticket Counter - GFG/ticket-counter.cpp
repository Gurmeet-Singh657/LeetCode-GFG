//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int i=1,j=N;
        int shift=K-1;
        while(i+shift<j-shift)
        {
            i+=K;
            j-=K;
        }
        // When all are completed
        if(i>j) return i; 
        // In case when first i's are removed and they were equal to K
        // No one left
        if(i+shift>=j)
            return j;
        // In case when first i's are taken
        return i+K;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends