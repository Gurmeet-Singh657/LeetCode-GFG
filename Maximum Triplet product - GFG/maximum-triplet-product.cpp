//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
        long long maxi1=-1e9,maxi2=-1e9,maxi3=-1e9;
        long long mini1=1e9,mini2=1e9;
        for(int i=0;i<n;i++)
        {
            if(maxi1<=arr[i])
            {
                maxi3=maxi2;
                maxi2=maxi1;
                maxi1=arr[i];
            }
            else if(maxi2<=arr[i])
            {
                maxi3=maxi2;
                maxi2=arr[i];
            }
            else if(maxi3<=arr[i])
            {
                maxi3=arr[i];
            }
            
            if(mini1>=arr[i])
            {
                mini2=mini1;
                mini1=arr[i];
            }
            else if(mini2>=arr[i])
            {
                mini2=arr[i];
            }
        }
        return max(maxi1*maxi2*maxi3,mini1*mini2*maxi1);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends