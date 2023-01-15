//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        bool flag=false;
        while(!q.empty())
        {
            int qsize=q.size();
            unordered_set<string> temp;
            while(qsize--)
            {
                vector<string> curr=q.front();
                q.pop();
                string str=curr[curr.size()-1];
                if(str==endWord)
                {
                    ans.push_back(curr);
                    flag=true;
                    continue;
                }
                for(int i=0;i<str.length();i++)
                {
                    char ch=str[i];
                    for(char currch='a';currch<='z';currch++)
                    {
                        str[i]=currch;
                        if(st.find(str)!=st.end())
                        {
                            curr.push_back(str);
                            q.push(curr);
                            temp.insert(str);
                            curr.pop_back();
                        }
                    }
                    str[i]=ch;
                }
            }
            if(flag==true) break;
            for(auto it:temp)
            {
                st.erase(it);
            }
        }
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