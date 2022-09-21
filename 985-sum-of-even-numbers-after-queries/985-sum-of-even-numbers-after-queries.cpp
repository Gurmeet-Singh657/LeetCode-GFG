class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_set<int> odd;
        unordered_set<int> even;
        vector<int> ans;
        int oddsum=0;
        int evensum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
            {
                odd.insert(i);
                oddsum+=nums[i];
            }
            else{
                even.insert(i);
                evensum+=nums[i];
            }
        }
        for(int i=0;i<queries.size();i++)
        {
            int val=queries[i][0];
            int index=queries[i][1];
            if(odd.size() && odd.find(index)!=odd.end())
            {
                if(val%2==0)
                {
                    oddsum+=val;
                }
                else
                {
                    odd.erase(index);
                    even.insert(index);
                    oddsum-=nums[index];
                    evensum+=nums[index];
                    evensum+=val;
                }
            }
            else
            {
                if(val%2==0)
                {
                    evensum+=val;
                }
                else
                {
                    even.erase(index);
                    odd.insert(index);
                    evensum-=nums[index];
                    oddsum+=nums[index];
                    oddsum+=val;
                }
            }
            nums[index]+=val;
            ans.push_back(evensum);
        }
        return ans;
    }
};