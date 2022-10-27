class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> countimg1;
        vector<pair<int,int>> countimg2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1)
                    countimg1.push_back({i,j});
                if(img2[i][j]==1)
                    countimg2.push_back({i,j});
            }
        }
        int maxans=0;
        map<pair<int,int>,int> mp;
        for(auto [i1,j1]:countimg1)
        {
            for(auto [i2,j2]:countimg2)
            {
                mp[{i2-i1,j2-j1}]++;
                maxans=max(maxans,mp[{i2-i1,j2-j1}]);
            }
        }
        return maxans;
    }
};