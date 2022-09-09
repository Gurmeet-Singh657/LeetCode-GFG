class Solution {
public:
    // sorting first parameter in inc order but if equal dec order so that 
    // that 2nd param should not be considered for equals
    // if no. greater coming for sure it came from other set of first parameter ahead
    static bool cmp(vector<int>& p1,vector<int>& p2)
    {
        if(p1[0]<p2[0]) return true;
        if(p1[0]==p2[0]) return p1[1]>p2[1];
        return false;
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        int ans=0;
        int maxi=INT_MIN;
        for(int i=properties.size()-1;i>=0;i--)  // starting from back first param obviously equal
            // but second param should be taken by maxi
        {
            if(properties[i][1]<maxi)
                ans++;
            maxi=max(maxi,properties[i][1]);
        }
        return ans;
    }
};