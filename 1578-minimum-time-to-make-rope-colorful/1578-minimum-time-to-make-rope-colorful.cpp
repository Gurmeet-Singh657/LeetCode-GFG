class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost=0;
        int maxi=neededTime[0];
        int count=1;
        int currcost=neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]==colors[i-1])
            {
                count++;
                maxi=max(maxi,neededTime[i]);
                currcost+=neededTime[i];
            }
            else{
                if(count>1)
                {
                    currcost-=maxi;
                    cost+=currcost;
                }
                currcost=neededTime[i];
                count=1;
                maxi=neededTime[i];
            }
        }
        if(count>1)
        {
            currcost-=maxi;
            cost+=currcost;
        }
        return cost;
    }
};