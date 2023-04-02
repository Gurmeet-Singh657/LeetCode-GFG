//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string s, string t, vector<string>& wL) {
        unordered_set<string> st(wL.begin(),wL.end());
        queue<string> q;
        q.push(s);
        int steps=1;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                string& curr=q.front();
                if(curr==t) return steps;
                q.pop();
                for(int i=0;i<curr.length();i++)
                {
                    char prev=curr[i];
                    for(char ch='a';ch<='z';ch++)
                    {
                        curr[i]=ch;
                        if(st.find(curr)!=st.end())
                        {
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[i]=prev;
                }
            }
            steps++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends