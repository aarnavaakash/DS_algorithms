class Solution {
public:
    bool isSubsequence(string s, string t) {
        map<char, vector<int>> mp;

        for(int i = 0; i<t.length(); i++) {
            char ch = t[i];
            mp[ch].push_back(i);
        }

        int prev = -1;

        for(char &ch : s) {
            if(mp.find(ch) == mp.end())
                return false;

            vector<int> indices = mp[ch];

            auto it = upper_bound(begin(indices), end(indices), prev);

            if(it == indices.end())
                return false;

            prev = *it;
        }

        return true;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m  = t.length();
        int n  = s.length();
        int i = 0, j = 0;

        while(i < m) {
            if(t[i] == s[j])
                j++;
            i++;
        }

        return j == n;
    }
};
