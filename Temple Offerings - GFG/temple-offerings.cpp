//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int offerings(int N, int arr[]){
        int larr[N]={0},rarr[N]={0};
        larr[0]=1;
        for(int i=1;i<N;i++)
        {
            if(arr[i]>arr[i-1]) larr[i]=larr[i-1]+1;
            else larr[i]=1;
        }
        rarr[N-1]=1;
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1]) rarr[i]=rarr[i+1]+1;
            else rarr[i]=1;
        }
        int ans=0;
        for(int i=0;i<N;i++)
        {
            ans+=max(larr[i],rarr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.offerings(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends