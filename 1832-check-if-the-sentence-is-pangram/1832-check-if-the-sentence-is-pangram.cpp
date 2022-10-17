class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> st;
        for(int i=0;i<sentence.length();i++)
        {
            st.insert(sentence[i]);
        }
        for(int i=0;i<26;i++)
        {
            char ch=(char)(i+'a');
            if(st.find(ch)==st.end())
                return false;
        }
        return true;
    }
};