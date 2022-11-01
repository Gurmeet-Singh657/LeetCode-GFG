class Solution {
public:
    int Checkball(vector<vector<int>>& arr,int col,int row)
    {  
        if(row==arr.size())
            return col;
        if(arr[row][col]==1 && col+1<arr[0].size() && arr[row][col+1]==1)
            return Checkball(arr,col+1,row+1);
        else if(arr[row][col]==-1 && col-1>=0 && arr[row][col-1]==-1)
            return Checkball(arr,col-1,row+1);
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int n=grid.size(),m=grid[0].size();
        for(int j=0;j<m;j++)
        {
            int num=Checkball(grid,j,0);
            ans.push_back(num);
        }
        return ans;
    }
};