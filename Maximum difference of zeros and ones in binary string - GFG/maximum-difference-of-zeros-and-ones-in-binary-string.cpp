//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    vector<int> arr;
	    int n=S.length();
	    for(int i=0;i<n;i++)
	    {
	        if(S[i]=='0') arr.push_back(1);
	        else arr.push_back(-1);
	    }
	    int maxsum=-1;
	    int currsum=0;
	    for(int i=0;i<n;i++)
	    {
	        currsum+=arr[i];
	        if(maxsum<currsum)
	            maxsum=currsum;
	        if(currsum<0) currsum=0;
	    }
	    return maxsum;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends