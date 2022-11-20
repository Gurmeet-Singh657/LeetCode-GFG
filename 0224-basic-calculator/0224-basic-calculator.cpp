class Solution {
public:
    int calculate(string s) {
        int result=0;
        stack<int> st;
        int sign=1;// positive
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                int ans=0;
                while(i<s.length() && isdigit(s[i]))
                {
                    ans=ans*10+(s[i]-'0');
                    i++;
                }
                i--;
                result+=sign*ans;
            }
            else if(s[i]=='+')
                sign=1;
            else if(s[i]=='-')
                sign=-1;
            else if(s[i]=='(')
            {
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                int currsign=st.top();
                st.pop();
                int currresult=st.top();
                st.pop();
                result=result*currsign+currresult;
            }
        }
        return result;
    }
};