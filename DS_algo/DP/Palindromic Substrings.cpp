class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<bool>> t(n, vector<bool>(n, false));

        int count = n;

        for(int i = 0; i<n; i++) {
            t[i][i] = true;
        }

        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;

                if(s[i] == s[j] && (t[i+1][j-1] || L == 2)) {
                    t[i][j] = true;
                    count++;
                }

            }
        }

        return count;
    }
};

class Solution {
public:
    int count = 0;
    void check(string s, int i, int j) {
        while(i >=0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        count = 0;

        for(int i = 0; i<n; i++) {
            check(s, i, i);
            check(s, i, i+1);
        }
        return count;
    }
};
