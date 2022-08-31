class Solution {
public:
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    void DFS(vector<vector<int>>& heights,vector<vector<bool>>& visited,int i,int j,vector<vector<int>>& ans)
    {
        if(visited[i][j])
            return;
        visited[i][j]=true;
        if(pacific[i][j] && atlantic[i][j])
            ans.push_back({i,j});
        
        if(i+1<heights.size() && heights[i+1][j]>=heights[i][j])
            DFS(heights,visited,i+1,j,ans);
        if(j+1<heights[0].size() && heights[i][j+1]>=heights[i][j])
            DFS(heights,visited,i,j+1,ans);
        if(i-1>=0 && heights[i-1][j]>=heights[i][j])
            DFS(heights,visited,i-1,j,ans);
        if(j-1>=0 && heights[i][j-1]>=heights[i][j])
            DFS(heights,visited,i,j-1,ans);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        atlantic=pacific=vector<vector<bool>>(n,vector<bool>(m,0));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            DFS(heights,pacific,i,0,ans);
            DFS(heights,atlantic,i,m-1,ans);
        }
        for(int i=0;i<m;i++)
        {
            DFS(heights,pacific,0,i,ans);
            DFS(heights,atlantic,n-1,i,ans);
        }
        return ans;
    }
};