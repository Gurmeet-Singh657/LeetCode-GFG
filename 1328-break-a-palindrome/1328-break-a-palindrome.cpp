class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length()==1) return "";
        int countas=0;
        for(int i=0;i<palindrome.length();i++)
        {
            if(palindrome[i]=='a')
                countas++;
        }
        if(countas==palindrome.length()) 
        {
            palindrome[palindrome.length()-1]='b';
            return palindrome;
        }
        if(countas==palindrome.length()-1)
        {
            palindrome[palindrome.length()-1]='b';
            return palindrome;
        }
        int i=0;
        while(i<palindrome.length() && palindrome[i]=='a')
            i++;
        palindrome[i]='a';
        return palindrome;
    }
};