class Solution {
public:

    bool isMatch(string text, string pattern) {
        if (pattern.length() == 0) {
            return text.length() == 0;
        }

        bool first_char_matched = false;
        if(text.length() > 0 && (pattern[0] == text[0] || pattern[0] == '.')) {
            first_char_matched = true;
        }

        if (pattern.length() >= 2 && pattern[1] == '*') {
            return (isMatch(text, pattern.substr(2)) ||
                    (first_char_matched && isMatch(text.substr(1), pattern)));
        } else {
            return first_char_matched && isMatch(text.substr(1), pattern.substr(1));
        }
    }
};

class Solution {
public:
    int t[21][21];

    bool solve(int i, int j, string& text, string& pattern) {
        if (j == pattern.length())
            return i == text.length();

        if (t[i][j] != -1) {
            return t[i][j];
        }

        bool ans = false;

        bool first_match = (i < text.length() &&
                            (pattern[j] == text[i] || pattern[j] == '.'));

        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
            ans = (solve(i, j + 2, text, pattern) ||
                   (first_match && solve(i + 1, j, text, pattern)));
        } else {
            ans = first_match && solve(i + 1, j + 1, text, pattern);
        }

        return t[i][j] = ans;
    }

    bool isMatch(string text, string pattern) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, text, pattern);
    }
};
