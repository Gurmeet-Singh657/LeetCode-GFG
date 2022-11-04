//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    void sortBySetBitCount(int arr[], int n)
    {
        vector<vector<int>> freq(32);
        for(int i=0;i<n;i++)
        {
            int setbits=__builtin_popcount(arr[i]);
            freq[setbits].push_back(arr[i]);
        }
        int index=0;
        for(int i=31;i>=0;i--)
        {
            vector<int> currarr=freq[i];
            for(auto it:currarr)
            {
                arr[index++]=it;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends