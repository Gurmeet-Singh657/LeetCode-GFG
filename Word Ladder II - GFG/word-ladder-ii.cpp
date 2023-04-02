//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void DFS(string& bw,unordered_map<string,int>& mp,int steps,vector<string> curr,vector<vector<string>>& ans)
    {
        if(steps==1)
        {
            reverse(curr.begin(),curr.end());
            ans.push_back(curr);
            reverse(curr.begin(),curr.end());
            return;
        }
        int nextsteps=steps-1;
        for(int i=0;i<bw.length();i++)
        {
            char prev=bw[i];
            for(char ch='a';ch<='z';ch++)
            {
                bw[i]=ch;
                if(mp.find(bw)!=mp.end() && mp[bw]==nextsteps)
                {
                    curr.push_back(bw);
                    DFS(bw,mp,steps-1,curr,ans);
                    curr.pop_back();
                }
            }
            bw[i]=prev;
        }
    }
    vector<vector<string>> findSequences(string bW, string eW, vector<string>& wL) {
        unordered_set<string> st(wL.begin(),wL.end());
        unordered_map<string,int> mp;
        queue<string> q;
        q.push(bW);
        int steps=2;
        mp[bW]=1;
        st.erase(bW);
        while(!q.empty())
        {
            bool flag=true;
            int qsize=q.size();
            while(qsize--)
            {
                string curr=q.front();
                q.pop();
                if(curr==eW)
                {
                    flag=false;
                    break;
                }
                for(int i=0;i<curr.length();i++)
                {
                    char prev=curr[i];
                    for(char ch='a';ch<='z';ch++)
                    {
                        curr[i]=ch;
                        if(st.find(curr)!=st.end())
                        {
                            mp[curr]=steps;
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[i]=prev;
                }
            }
            if(flag==false) break;
            steps++;
        }
        steps-=1;
        if(mp.find(eW)==mp.end()) return {};
        vector<vector<string>> ans;
        vector<string> curr;
        curr.push_back(eW);
        DFS(eW,mp,steps,curr,ans);
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends