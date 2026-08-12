int t[101][27][101][101];
class Solution {
public:

    int solve(string &s, int i, int prev, int freq, int k ){
        if(k < 0)
            return INT_MAX;

        if(i >= s.length())
            return 0;

        if(t[i][prev][freq][k] != -1) {
            return t[i][prev][freq][k];
        }

        int delete_i = solve(s, i+1, prev, freq, k-1);

        int keep_i   = 0;

        if(s[i] - 'a' == prev) {
             int one_more_added = 0;
             if(freq == 1 || freq == 9 || freq == 99) {
                 one_more_added = 1;
             }
            keep_i = one_more_added + solve(s, i+1, prev, freq+1, k);
        } else {
            keep_i = 1 + solve(s, i+1, s[i]-'a', 1, k);
        }

        return t[i][prev][freq][k] = min(delete_i, keep_i);
    }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(t, -1, sizeof(t));
        return solve(s, 0, 26, 0, k);
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(int i, int k, string &s) {
        if(k < 0) {
            return 100000;
        }

        if(i >= n || (n-i) <= k) {
            return 0;
        }

        if(t[i][k] != -1) {
            return t[i][k];
        }

        int delete_i = solve(i+1, k-1, s);

        int keep_i = INT_MAX;

        int deleted  = 0;
        int freq     = 0;
        int addition = 0;

        for(int j = i; j < n && deleted <= k; j++) {
            if(s[j] == s[i]) {
                freq++;
                if(freq == 2 || freq == 10 || freq == 100) {
                    addition++;
                }
            } else {
                deleted++;
            }

            keep_i = min(keep_i, 1 + addition + solve(j+1, k-deleted, s));
        }

        return t[i][k] = min(delete_i, keep_i);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        t = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, s);
    }
};
