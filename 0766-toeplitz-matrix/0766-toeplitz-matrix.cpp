class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int diag=n+m-1;
        for(int d=0;d<diag;d++)
        {
            int row,col;
            if(d<n)
            {
                row=n-1-d;
                col=0;
            }
            else
            {
                row=0;
                col=d-(n-1);
            }
            vector<int> ans;
            while(row<n && col<m)
            {
                ans.push_back(matrix[row][col]);
                row++;
                col++;
            }
            for(int i=1;i<ans.size();i++)
            {
                if(ans[i]!=ans[i-1])
                    return false;
            }
        }
        return true;
    }
};