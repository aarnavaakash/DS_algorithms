class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0;

        int n = s.length();
        int i = 0;
        int j = 0;
        while(j < n) {
            if(!st.count(s[j])) {
                st.insert(s[j]);
                l = max(l, (int)st.size());
                j++;
            } else {
                st.erase(s[i]);
                i++;

            }
        }
        return l;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0;

        int i = 0, j = 0;
        unordered_map<char, int> mp;

        while(j < n) {
            char ch = s[j];
            if(!mp.count(ch)) {

                mp[ch] = j;
                res = max(res, j-i+1);
            } else {

                i = max(i, mp[ch] + 1);
                mp[ch] = j;
                res = max(res, j-i+1);
            }
            j++;
        }

        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0;

        int i = 0, j = 0;
        unordered_map<char, int> mp;

        while(j < n) {
            char ch = s[j];
            if(mp.count(ch)) {
                i = max(i, mp[ch] + 1);
            }
            mp[ch] = j;
            res = max(res, j-i+1);
            j++;
        }

        return res;
    }
};
