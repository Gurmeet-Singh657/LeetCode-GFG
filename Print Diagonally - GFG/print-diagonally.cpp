//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		vector<int> ans;
		for(int col=0;col<N;col++)
		{
		    int row=0;
		    int currcol=col;
		    while(row<N &&currcol>=0)
		    {
		        ans.push_back(A[row][currcol]);
		        row++;
		        currcol--;
		    }
		}
		for(int row=1;row<N;row++)
		{
		    int col=N-1;
		    int currrow=row;
		    while(currrow<N &&col>=0)
		    {
		        ans.push_back(A[currrow][col]);
		        currrow++;
		        col--;
		    }
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends