//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int arr[],int N,int K,int mid)
    {
        int count=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if(sum+arr[i]>mid)
            {
                count++;
                sum=arr[i];
            }
            else
            {
                sum+=arr[i];
            }
        }
        return count<=K; 
    }
    int splitArray(int arr[] ,int N, int K) {
        int start=*max_element(arr,arr+N),end=accumulate(arr,arr+N,0);
        int ans=INT_MAX;
        while(start<=end)
        {
            int mid=(start+end)/2;
            bool possible=check(arr,N,K,mid);
            if(possible)
            {
                ans=min(ans,mid);
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends