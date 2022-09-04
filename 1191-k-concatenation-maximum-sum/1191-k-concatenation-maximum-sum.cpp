#define mod (int)(1e9+7)
class Solution {
public:
    int kadanesum(vector<int> &arr)
    {
        int currsum =0,maxsum=0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (currsum >= 0)
                currsum += arr[i];
            else
                currsum = arr[i];
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
            sum += arr[i];
        if (k == 1)
            return kadanesum(arr);
        else if (sum < 0)
        {
            arr.insert(arr.end(), arr.begin(), arr.end());
            return kadanesum(arr);
        }
        else
        {
            arr.insert(arr.end(), arr.begin(), arr.end());
            return (kadanesum(arr) + ((k - 2) * 1LL*sum)%mod)%mod;
        }
        return 0;
    }
};