class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans="";
        string curr="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {   
                if(curr!="")
                st.push(curr);
                curr="";
            }
            else
            {
                curr+=s[i];
            }
        }
        if(curr!="")
           st.push(curr);
     while(!st.empty())
     {
         string now=st.top();
         st.pop();
         ans+=now;
         if(st.size()!=0)
         ans+=" ";
     }
        return ans;
    }
};