//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void FindUnique(int n,vector<vector<int>>& ans,vector<int>& currans,int temp)
	{
	    if(n==0)
	    {
	        ans.push_back(currans);
	        return;
	    }
	    for(int i=min(temp,n);i>=1;i--)
	    {
	        currans.push_back(i);
	        FindUnique(n-i,ans,currans,i);
	        currans.pop_back();
	    }
	}
    vector<vector<int>> UniquePartitions(int n) {
        vector<vector<int>> ans;
        vector<int> currans;
        FindUnique(n,ans,currans,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends