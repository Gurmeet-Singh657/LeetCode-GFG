//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int> q;
        q.push(start);
        bool visited[100000]={0};
        visited[start]=1;
        int steps=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                auto it=q.front();
                q.pop();
                if(it==end) return steps;
                for(int i=0;i<arr.size();i++)
                {
                    long long mul=arr[i]*it;
                    mul%=100000;
                    if(!visited[mul])
                    {
                        visited[mul]=true;
                        q.push(mul);
                    }
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