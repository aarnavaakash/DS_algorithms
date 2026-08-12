class Solution {
public:
    typedef unsigned long long ull;
    ull cache[1001][1001];
    ull solve(string& s, string& t, int m, int n) {
        if(n == 0)
            return cache[m][n] = 1;
        if(m == 0)
            return cache[m][n] = 0;

        if(cache[m][n] != -1)
            return cache[m][n];

        if(s[m-1] == t[n-1])
            return cache[m][n] = solve(s, t, m-1, n) + solve(s, t, m-1, n-1);
        else
            return cache[m][n] = solve(s, t, m-1, n);
    }
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        memset(cache, -1, sizeof(cache));
        return solve(s, t, m, n);
    }
};

class Solution {
public:
    typedef unsigned long long ull;
    ull solve(string& s, string& t, int m, int n) {
        vector<vector<ull>> cache(m+1, vector<ull>(n+1));

        for(int row = 0; row<m+1; row++) {
            cache[row][0] = 1;
        }

        for(int col = 1; col<n+1; col++) {
            cache[0][col] = 0;
        }

        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(s[i-1] == t[j-1])
                    cache[i][j] = cache[i-1][j-1] + cache[i-1][j];
                else
                    cache[i][j] = cache[i-1][j];
            }
        }

        return cache[m][n];
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        return solve(s, t, m, n);
    }
};

class Solution {
public:
    typedef unsigned long long ull;

    ull solve(string& s, string& t, int m , int n) {
        vector<ull> curr(m+1, 0);
        vector<ull> prev(n+1, 0);

        prev[0] = curr[0] = 1;

        for(int i = 1; i<m+1; i++) {

            for(int j = 1; j<n+1; j++) {

                if(s[i-1] == t[j-1])
                    curr[j] = prev[j-1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[n];
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n)
            return 0;
        return solve(s, t, m, n);
    }
};
