//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
         int maxi=INT_MIN;
         for(int i=0;i<arr.size();i++)
         {
             int curr=arr[i]+k;
             int count=0;
             for(int j=0;j<arr.size();j++)
             {
                 if(arr[j]>=arr[i] && arr[j]<=curr)
                 {
                     count++;
                 }
             }
             maxi=max(maxi,count);
         }
         return arr.size()-maxi;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends