class Solution {
public:
    void f(int n,int k,vector<int>& ans,string str)
    {
        if(n==0)
        {
            ans.push_back(stoi(str));
            return;
        }
        char ch=str[str.size()-1];
        int prev=ch-'0';
        for(int i=0;i<=9;i++)
        {
            if(abs(prev-i)==k)
                f(n-1,k,ans,str+to_string(i));
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            f(n-1,k,ans,to_string(i));
        }
        return ans;
    }
};