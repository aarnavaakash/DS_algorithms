class Solution {
public:
    unordered_set<string> st;
    int t[301];
    int n;

    bool solve(string &s, int idx) {

        if(idx == n) {
            return true;
        }

        if(st.find(s.substr( idx , n - idx )) != st.end()) {
            return true;
        }

        if(t[idx] != -1)
            return t[idx];

        for(int l = 1; l<=n; l++) {

            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l))
                return t[idx] = true;

        }

        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        memset(t, -1, sizeof(t));

        for(string &word : wordDict) {
            st.insert(word);
        }

        return solve(s, 0);
    }
};

class Solution {
public:
    bool solve(string s, vector<string>& wordDict) {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.length();
        vector<bool> t(n+1, false);

        t[0] = true;

        for(int i = 1; i<=n; i++) {

            for(int j = 0; j<i; j++) {
                string temp = s.substr(j, i-j);

                if(st.count(temp) && t[j]) {

                    t[i] = true;
                    break;
                }
            }
        }
        return t[n];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict);
    }
};
