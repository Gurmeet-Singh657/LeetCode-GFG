//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
using namespace std;
class Solution{

    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        vector<long long> prefixSum(n+2,0);
        vector<long long> suffixSum(n+2,0);
        for(int i=0;i<n;i++)
        {
            int ind=i+1;
            prefixSum[ind]+=a[i]+prefixSum[ind-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            int ind=i+1;
            suffixSum[ind]+=a[i]+suffixSum[ind+1];
        }
        for(int i=1;i<=n;i++)
        {
            if(prefixSum[i-1]==suffixSum[i+1])
            {
                return i;
            }
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends