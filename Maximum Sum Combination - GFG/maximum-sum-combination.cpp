//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    #define ppi pair<int,pair<int,int>>
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end(),greater<int>{});
        sort(B.begin(),B.end(),greater<int>{});
        set<pair<int,int>> st;
        int i=N-1,j=N-1;
        vector<int> ans;
        priority_queue<ppi> pq;
        pq.push({A[0]+B[0],{0,0}});
        while(!pq.empty() && K--)
        {
            auto curr=pq.top();
            int sum=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            
            pq.pop();
            ans.push_back(sum);
            if(i+1<N && st.find({i+1,j})==st.end())
            {
                st.insert({i+1,j});
                pq.push({A[i+1]+B[j],{i+1,j}});
            }
            if(j+1<N && st.find({i,j+1})==st.end())
            {
                st.insert({i,j+1});
                pq.push({A[i]+B[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends