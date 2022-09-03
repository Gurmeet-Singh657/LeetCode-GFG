class Solution {
public:
    void f(int n,int k,vector<int>& ans,string str,int prev)
    {
        if(n==0)
        {
            ans.push_back(stoi(str));
            return;
        }
        for(int i=0;i<=9;i++)
        {
            if(abs(prev-i)==k)
                f(n-1,k,ans,str+to_string(i),i);
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            f(n-1,k,ans,to_string(i),i);
        }
        return ans;
    }
};