//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int n=A.length();
		    queue<int> q;
		    int freq[26]={0};
		    string ans="";
		    for(int i=0;i<n;i++)
		    {
		        int num=A[i]-'a';
		        freq[num]++;
		        if(freq[num]==1)
		        {
		            q.push(num);
		        }
		        while(!q.empty() && freq[q.front()]>1)
		        {
		            q.pop();
		        }
		        if(q.empty())
		        {
		            ans.push_back('#');
		        }
		        else
		        {
		            ans.push_back((char)(q.front()+'a'));
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends