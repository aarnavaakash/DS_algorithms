class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        for(int i = 0; i < s.length(); i++) {

            if(!memcmp(s.c_str(), rev.c_str() + i, s.length()-i)) {
                return rev.substr(0, i) + s;
            }
        }

        return rev + s;
    }
};

class Solution {
public:

    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        string temp = s + "-" + rev;

        vector<int> LPS(temp.length(), 0);
        computeLPS(temp, LPS);

        int longestLPSLength = LPS[temp.length()-1];

        string culprit = rev.substr(0, s.length() - longestLPSLength);

        return culprit + s;
    }
};
