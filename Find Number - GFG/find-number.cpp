//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int arr[5]={1,3,5,7,9};
    long long findNumber(long long N){
        long long ans=0;
        long long num=1;
        while(N>0)
        {
            int rem=(N-1)%5;
            ans=ans+arr[rem]*num;
            N=(N-1)/5;
            num*=10;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends