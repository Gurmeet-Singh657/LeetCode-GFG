class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++)
        {
            pq.push({abs(x-arr[i]),arr[i]});
        }
        int n=arr.size();
        for(int i=k;i<n;i++)
        {
            if(pq.top().first>abs(arr[i]-x))
            {
                pq.pop();
                pq.push({abs(x-arr[i]),arr[i]});
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};