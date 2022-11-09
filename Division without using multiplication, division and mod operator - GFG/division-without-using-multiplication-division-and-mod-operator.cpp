//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        long long a=dividend,b=divisor;
        int sign=1;
        if((a>0 && b<0) || (a<0 && b>0)) sign=-1;
        if(a<0) a=-a;
        if(b<0) b=-b;
        long long int ans=0,temp=0;
        for(int i=31;i>=0;i--)
        {
            if(temp+(b<<i)<=a)
            {
                temp+=(b<<i);
                ans+=(1ll<<i);
            }
        }
        ans*=sign;
        if(ans>INT_MAX || ans<INT_MIN) ans=INT_MAX;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends