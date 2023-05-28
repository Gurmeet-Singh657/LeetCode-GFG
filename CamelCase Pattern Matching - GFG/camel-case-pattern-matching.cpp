//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> ans;
        for(int i=0;i<N;i++)
        {
            string curr=Dictionary[i];
            int ptr=0;
            for(int j=0;j<curr.size();j++)
            {
                if(isupper(curr[j]))
                {
                    if(curr[j]==Pattern[ptr]) ptr++;
                    else break;
                }
                if(ptr==Pattern.size()) break;
            }
            if(ptr==Pattern.size()) ans.push_back(curr);
        }
        if(ans.size()==0) ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends