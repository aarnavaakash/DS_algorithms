class Solution {
public:
    int t[1001][1001];
    int LPS(string& s, int i, int j) {
        if(i > j)
            return 0;
        if(i == j)
            return 1;

        if(t[i][j] != -1)
            return t[i][j];
        if(s[i] == s[j])
            return t[i][j] = 2 + LPS(s, i+1, j-1);
        else
            return t[i][j] = max(LPS(s, i+1, j), LPS(s, i, j-1));
    }

    int longestPalindromeSubseq(string s) {
        int m = s.length();
        memset(t, -1, sizeof(t));

        return LPS(s, 0, m-1);

    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        vector<vector<int>> t(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            t[i][i] = 1;
        }

        for(int L = 2; L<=n; L++) {
            for(int i = 0; i < n-L+1; i++) {
                int j = i + L - 1;

                if(s[i] == s[j]) {
                    t[i][j] = 2 + t[i+1][j-1];
                } else {
                    t[i][j] = max(t[i][j-1], t[i+1][j]);
                }
            }
        }

        return t[0][n-1];

    }
};

class Solution {
public:

    int LCS(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(m+1));

        for(int row = 0; row<m+1; row++) {
            t[row][0] = 0;
        }

        for(int col = 0; col<n+1; col++) {
            t[0][col] = 0;
        }

        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }

        return t[m][n];
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;

        reverse(s1.begin(), s1.end());
        int m = s.length();

        return LCS(s, s1, m, m);

    }
};
