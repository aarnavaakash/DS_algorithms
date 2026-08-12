************************************ C++ ************************************

class Solution {
public:
    int m, n, N;
    int t[101][101][201];

    bool solve(int i, int j, int k, string& s1, string& s2, string& s3) {

        if(i == m && j == n && k == N) {
            return true;
        }

        if(k >= N)
            return false;

        if(t[i][j][k] != -1)
            return t[i][j][k];

        bool result = false;

        if(i < m && s1[i] == s3[k]) {
            result = solve(i+1, j, k+1, s1, s2, s3);
        }

        if(result == true)
            return t[i][j][k] = result;

        if(j < n && s2[j] == s3[k]) {
            result = solve(i, j+1, k+1,s1, s2, s3);
        }
        return t[i][j][k] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0, s1, s2, s3);
    }
};

class Solution {
public:
    int m, n, N;
    int t[101][101];

    bool solve(int i, int j, string& s1, string& s2, string& s3) {

        if(i == m && j == n && i+j == N) {
            return true;
        }

        if(i+j >= N)
            return false;

        if(t[i][j] != -1)
            return t[i][j];

        bool result = false;

        if(i < m && s1[i] == s3[i+j]) {
            result = solve(i+1, j, s1, s2, s3);
        }

        if(result == true)
            return t[i][j] = result;

        if(j < n && s2[j] == s3[i+j]) {
            result = solve(i, j+1, s1, s2, s3);
        }
        return t[i][j] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        memset(t, -1, sizeof(t));
        return solve(0, 0, s1, s2, s3);
    }
};

class Solution {
public:
    bool check(string& s1, string& s2, string& s3) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        if(m + n != N)
            return false;

        int t[m+1][n+1];

        t[0][0] = true;

        for(int j = 1; j<n+1; j++) {
            t[0][j] = t[0][j-1] && s2[j-1]==s3[j-1];
        }

        for(int i = 1; i<m+1; i++) {
            t[i][0] = t[i-1][0] && s1[i-1]==s3[i-1];
        }

        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                int k = i + j - 1;

                bool s1_equals_s3  = t[i-1][j] && s1[i-1] == s3[k];

                bool s2_equals_s3  = t[i][j-1] && s2[j-1] == s3[k];

                t[i][j] = s1_equals_s3 || s2_equals_s3 ;
            }
        }

        return t[m][n];
    }

    bool isInterleave(string s1, string s2, string s3) {
        return check(s1, s2, s3);
    }
};

class Solution {
public:
    bool check(string& s1, string& s2, string& s3) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        if(m + n != N)
            return false;

        bool t[n+1];

        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 && j == 0) {
                    t[j] = true;
                } else if(i == 0) {
                    t[j] = t[j-1] && s2[j-1]==s3[i+j-1];
                } else if (j == 0) {
                    t[j] = t[j] && s1[i-1]==s3[i+j-1];
                } else {
                    t[j] = (t[j-1] && s2[j-1]==s3[i+j-1]) || (t[j] && s1[i-1]==s3[i+j-1]);
                }
            }
        }

        return t[n];
    }

    bool isInterleave(string s1, string s2, string s3) {
        return check(s1, s2, s3);
    }
};

************************************ JAVA ************************************
class Solution {
    int m, n, N;
    Boolean dp[][];
    boolean check(String s1, String s2, String s3, int i, int j) {
        if(i >= m && j >= n && i+j >= N)
            return true;

        if(i+j >= N)
            return false;

        if(dp[i][j] != null)
            return dp[i][j];

        boolean result = false;

        if(i < m && s1.charAt(i) == s3.charAt(i+j)){
            result = check(s1, s2, s3, i+1, j);
        }

        if(result == true){
            return dp[i][j] = result;
        }

        if(j < n && s2.charAt(j) == s3.charAt(i+j)){
            result = check(s1, s2, s3, i, j+1);
        }
        return dp[i][j] = result;
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();

        if(m + n != N)
            return false;

        dp = new Boolean[m+1][n+1];
        return check(s1, s2, s3, 0, 0);

    }
}
