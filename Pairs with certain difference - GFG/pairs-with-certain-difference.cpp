//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int f(int ind,int arr[],int N,int K)
    {
        if(ind==-1) return 0;
        if(ind-1>=0 && arr[ind]-arr[ind-1]<K)
        return arr[ind]+arr[ind-1]+f(ind-2,arr,N,K);
        else 
        return f(ind-1,arr,N,K);
    }
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr,arr+N);
        return f(N-1,arr,N,K);   
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends