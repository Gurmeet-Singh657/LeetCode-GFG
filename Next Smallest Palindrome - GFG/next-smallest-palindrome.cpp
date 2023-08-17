//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int curr[], int n) {
	    vector<int> num(curr,curr+n);
	    int i=0,j=n-1;
	    int change=1;
	    while(i<j)
	    {
	        if(num[i]>num[j]) change=0;
	        if(num[i]<num[j]) change=1;
	        num[j]=num[i];
	        i++;
	        j--;
	    }
	    i=n/2;
	    while(change && i<n)
	    {
	        if(num[i]==9)
	        {
	            num[i]=0;
	            num[n-i-1]=num[i];
	        }
	        else
	        {
	            num[i]+=1;
	            num[n-i-1]=num[i];
	            change=0;
	        }
	        i++;
	    }
	    if(change) num[0]=1,num.push_back(1);
	    return num;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends