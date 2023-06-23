//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        int freq[26]={0};
        for(auto it:tasks) freq[it-'A']++;
        int maxFreq=*max_element(freq,freq+26);
        int lastExtras=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]==maxFreq) lastExtras++;
        }
        return max(N,maxFreq+(maxFreq-1)*K+(lastExtras-1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends