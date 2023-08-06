//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int>& p1,pair<int,int>& p2)
    {
        if(p1.second<p2.second) return true;
        if(p1.second==p2.second && p1.first<p2.first) return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meets;
        for(int i=0;i<n;i++)
        {
            meets.push_back({start[i],end[i]});
        }
        sort(meets.begin(),meets.end(),cmp);
        int first=meets[0].second;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(meets[i].first>first)
            {
                first=meets[i].second;
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends