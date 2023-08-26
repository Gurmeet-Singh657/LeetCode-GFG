//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        int mini=0;
        int i=0,j=N-1;
        sort(candies,candies+N);
        while(i<=j)
        {
            mini+=candies[i];
            i++;
            j-=K;
        }
        int maxi=0;
        i=0,j=N-1;
        sort(candies,candies+N,greater<int>{});
        while(i<=j)
        {
            maxi+=candies[i];
            i++;
            j-=K;
        }
        return {mini,maxi};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends