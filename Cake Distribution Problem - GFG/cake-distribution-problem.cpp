//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    #define ll long long int
    bool check(int mid,vector<int>& sweetness,int N,int K)
    {
        int sum=0;
        int count=0;
        for(int i=0;i<N;i++)
        {
            sum+=sweetness[i];
            if(sum>=mid)
            {
                count++;
                sum=0;
            }
        }
        if(sum>=mid) count++;
        return count>=K+1;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        ll start=1,end=(ll)1e14;
        ll ans=-1;
        while(start<=end)
        {
          ll mid=(start+end)/2LL;
          if(check(mid,sweetness,N,K))
          {
              ans=mid;
              start=mid+1;
          }
          else
          {
              end=mid-1;
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
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends