class Solution {
public:
    int f(vector<int> bits,vector<string>& arr,int ind,int totalbits)
    {
        if(ind==0)
        {
            if(bits[0]!=0 && (bits[0] & totalbits)==0)
                return arr[0].length();
            return 0;
        }
        int nottake=f(bits,arr,ind-1,totalbits);
        int take=0;
        if(bits[ind]!=0 && ((bits[ind] & totalbits)==0))
        {
            take=arr[ind].length() + f(bits,arr,ind-1,(totalbits | bits[ind]));
        }
        return max(take,nottake);
    }
    int maxLength(vector<string>& arr) {
        vector<int> bits;
        for(int i=0;i<arr.size();i++)
        {
            string curr=arr[i];
            int ans=0;
            for(int j=0;j<curr.length();j++)
            {
                if((ans & 1<<(curr[j]-'a'))!=0) // means this bit is already set
                {
                    ans=0;
                    break;
                }
                ans=ans | (1<<(curr[j]-'a'));
            }  
            bits.push_back(ans);
        }
        return f(bits,arr,arr.size()-1,0);
    }
};