class Solution {
public:
    int t[1001][1001];

    bool solve(string &s, int l, int r){
        if(l >= r)
            return 1;

        if(t[l][r] != -1){
            return t[l][r];
        }

        if(s[l] == s[r]) {
            return t[l][r] = solve(s, l+1, r-1);
        }

        return t[l][r] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        int maxlen = INT_MIN;
        int startingIndex = 0;

        memset(t, -1, sizeof(t));

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                if(solve(s, i, j)) {
                    if(j-i+1 > maxlen){
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                }

            }
        }

        return s.substr(startingIndex, maxlen);
    }
};

class Solution {
public:
    bool solve(string &s, int l, int r){

        while(l <= r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        int maxlen = INT_MIN;
        int startingIndex = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                if(solve(s, i, j)) {
                    if(j-i+1 > maxlen){
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                }

            }
        }

        return s.substr(startingIndex, maxlen);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        int maxL  = 0;
        int index = 0;

        vector<vector<bool>> t(n, vector<bool>(n));

        maxL = 1;
        for(int i = 0; i<n; i++) {
            t[i][i] = true;

        }

        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;

                if(s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxL = 2;
                    index = i;
                } else if (s[i] == s[j] && t[i+1][j-1] == true) {
                    t[i][j] = true;
                    if(j-i+1 > maxL) {
                        maxL = j-i+1;
                        index = i;
                    }
                } else {
                    t[i][j] = false;
                }

            }
        }

        return s.substr(index, maxL);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        int maxL = 1;
        int start = 0;

        for(int i = 0; i<n; i++)
            t[i][i] = true;

        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;

                if(s[i] == s[j] && (t[i+1][j-1] || L == 2)) {
                    t[i][j] = true;
                    if(L > maxL) {
                        maxL = L;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxL);
    }
};
