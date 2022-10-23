class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> st;
        int repeating=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i])!=st.end())
            {
                repeating=nums[i];
            }
            st.insert(nums[i]);
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(st.find(i)==st.end())
                return {repeating,i};
        }
    return {-1,-1};
    }
};