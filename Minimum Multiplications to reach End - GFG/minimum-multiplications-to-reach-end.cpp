//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    #define MOD (int)(1e5)
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int> q;
        vector<bool> vis(1000001,0);
        q.push(start);
        vis[start]=true;
        int steps=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                int num=q.front();
                q.pop();
                if(num==end) return steps;
                
                for(auto ele:arr)
                {
                    int mul=(num*1LL*ele)%MOD;
                    if(vis[mul]) continue;
                    q.push(mul);
                    vis[mul]=true;
                }
            }
            steps++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends