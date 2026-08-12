class Solution {
public:
    int M = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    vector<vector<long long>> t;
    long long solve(int ch, int n) {
        if(n == 0) {
            return 1;
        }

        if(t[ch][n] != -1) {
            return t[ch][n];
        }

        if(ch == a) {
            return t[ch][n] = solve(e, n-1) % M;
        } else if(ch == e) {
            return t[ch][n] = (solve(a, n-1) + solve(i, n-1)) % M;
        } else if(ch == i) {
            return t[ch][n] = (solve(a, n-1) + solve(e, n-1) + solve(o, n-1) + solve(u, n-1)) % M;
        } else if(ch == o) {
            return t[ch][n] = (solve(i, n-1) + solve(u, n-1)) % M;
        } else {
            return t[ch][n] = solve(a, n-1);
        }

        return t[ch][n] = 0;
    }

    int countVowelPermutation(int n) {
        t.resize(5, vector<long long>(n+1, -1));
        long result = 0;

        result = (result + solve(a, n-1)) % M;
        result = (result + solve(e, n-1)) % M;
        result = (result + solve(i, n-1)) % M;
        result = (result + solve(o, n-1)) % M;
        result = (result + solve(u, n-1)) % M;

        return result;

    }
};

class Solution {
public:
    int M = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    int countVowelPermutation(int n) {

        long long t[5][n+1];

        for(int vowel = 0; vowel <= 4; vowel++) {
            t[vowel][1] = 1;
        }

        for(int len = 2; len <= n; len++) {
            t[a][len] = (t[e][len-1] + t[i][len-1] + t[u][len-1]) % M;

            t[e][len] = (t[a][len-1] + t[i][len-1]) % M;

            t[i][len] = (t[e][len-1] + t[o][len-1]) % M;

            t[o][len] = (t[i][len-1]) % M;

            t[u][len] = (t[i][len-1] + t[o][len-1]) % M;
        }

        long long result = 0;
        for(int vowel = 0; vowel <= 4; vowel++) {
            result = (result + t[vowel][n]) % M;
        }
        return result;

    }
};
