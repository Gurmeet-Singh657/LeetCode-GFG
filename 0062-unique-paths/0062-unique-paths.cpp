class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<int> ahead(m+1,0);
        ahead[m-1]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1) continue;
                int down=ahead[j];
                int right=ahead[j+1];
                ahead[j]=down+right;
            }
        }
        return ahead[0];
    }
};