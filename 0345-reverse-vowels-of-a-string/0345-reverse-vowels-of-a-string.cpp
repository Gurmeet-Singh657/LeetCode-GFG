class Solution {
public:
    bool isvowel(char ch)
    {
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
    string reverseVowels(string s) {
        int i=-1,j=s.length();
        while(i<j)
        {
            do
            {
                i++;
            }while(i<s.length() && !isvowel(s[i]));
            do{
                j--;
            }while(j>=0 && !isvowel(s[j]));
            if(i>=j) return s;
            swap(s[i],s[j]);
        }
        return s;
    }
};