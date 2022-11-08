class Solution {
public:
    string makeGood(string s) {
         while (s.size() > 1) {
            bool find = false;
            for (int i = 0; i < s.size() - 1; ++i) {
                char currChar = s[i], nextChar = s[i + 1];
                if (abs(currChar - nextChar) == 32) {
                    s = s.substr(0, i) + s.substr(i + 2);
                    find = true;
                    break;
                }
            }
            if (!find)
                break;
        }
        return s;
    }
};