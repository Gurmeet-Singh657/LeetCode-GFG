//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    #define MOD (int)(1e9+7)
    long long int findMaxProduct(vector<int>&a, int n){
        sort(a.begin(),a.end());
        if(n==1) return a[0];
        else if(a[0]==0 && a[n-1]==0) return 0;
        if(n==2 && a[0]<0 && a[1]==0) return 0;
        if(a[0]<0 && a[1]==0 && a[n-1]==0) return 0;
        long long int ans=1;
        for(int i=n-1;i>=0 && a[i]>0;i--)
        {
            ans=(ans*1LL*a[i])%MOD;
        }
        int negpro=1;
        for(int i=0;i<n && a[i]<0;i++)
        {
            negpro=(negpro*1LL*a[i])%MOD;
            if(negpro>0) ans=(ans*1LL*negpro)%MOD,negpro=1;
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends