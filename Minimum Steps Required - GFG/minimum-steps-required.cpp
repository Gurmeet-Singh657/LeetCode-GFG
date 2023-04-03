//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int count=1;
    // aabbbaabba
    for(int i=1;i<str.length();i++)
    {
        if(str[i]==str[i-1]) continue;
        count++;
    }
    return (count+2)/2;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends