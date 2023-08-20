//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    int cell=0;
                    for(int x=-1;x<=1;x++)
                    {
                        for(int y=-1;y<=1;y++)
                        {
                            int row=i+x,col=j+y;
                            if(row>=0 && col>=0 && row<n && col<m && matrix[row][col]==0) cell++;
                        }
                    }
                    if(cell%2==0 && cell>0) count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends