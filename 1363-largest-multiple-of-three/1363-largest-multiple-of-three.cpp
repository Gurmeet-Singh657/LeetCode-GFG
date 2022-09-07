class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int sum=0;
        vector<int> freq(10,0);
        sort(digits.rbegin(),digits.rend());
        string ans="";
        for(int i=0;i<digits.size();i++)
         { 
            freq[digits[i]]++;
            sum+=digits[i];
            ans+=to_string(digits[i]);
         }
        if(digits[0]==0) return "0";
        if(sum%3==0) return ans;
        else if(sum%3==1)
        {
            for(int i=ans.size()-1;i>=0;i--)
            {
                if((ans[i]-'0')%3==1)
                {
                    ans.erase(i,1);
                    if(ans[0]=='0') return "0";
                    return ans;
                }
            }
            int curr1=-1,curr2=-1;
            for(int i=ans.size()-1;i>=0;i--)
            {
                if(curr1==-1 && (ans[i]-'0')%3==2)
                    curr1=i;
                else if(curr2==-1 && (ans[i]-'0')%3==2)
                {
                    curr2=i;
                    break;
                }
            }
            if(curr1!=-1 && curr2!=-1)
            {
                ans.erase(curr1,1);
                ans.erase(curr2,1);
                 if(ans[0]=='0') return "0";
                    return ans;
            }
            return "";
        }
        else if(sum%3==2)
        {
            for(int i=ans.size()-1;i>=0;i--)
            {
                if((ans[i]-'0')%3==2)
                {
                    ans.erase(i,1);
                     if(ans[0]=='0') return "0";
                    return ans;
                }
            }
            int curr1=-1,curr2=-1;
            for(int i=ans.size()-1;i>=0;i--)
            {
                if(curr1==-1 && (ans[i]-'0')%3==1)
                    curr1=i;
                else if(curr2==-1 && (ans[i]-'0')%3==1)
                {
                    curr2=i;
                    break;
                }
            }
            if(curr1!=-1 && curr2!=-1)
            {
                ans.erase(curr1,1);
                ans.erase(curr2,1);
                 if(ans[0]=='0') return "0";
                    return ans;
            }
            return "";
        }
        return "";
    }
};