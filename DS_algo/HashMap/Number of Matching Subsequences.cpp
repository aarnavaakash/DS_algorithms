class Solution {
public:
    bool isSubsequence(const string &s1, const string &s2) {
        int m = s1.length();
        int n  = s2.length();
        int i = 0, j = 0;

        while(i < m) {
            if(s1[i] == s2[j])
                j++;
            i++;
        }

        return j == n;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string, int> mp;
        for(string &word : words) {
            mp[word]++;
        }

        for(auto &it : mp) {
            if(isSubsequence(s, it.first)) {
                count += it.second;
            }
        }

        return count;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<string>> mp;

        for(string &word : words) {
            mp[word.back()].push_back(word);
        }
        int n = s.length();
        int count =  0;
        for(int i = n-1; i>=0 ; i--) {
            char ch = s[i];
            if(mp.find(ch) == mp.end())
                continue;
            vector<string> candidates = mp[ch];
            mp[ch].clear();
            for(string &word : candidates) {
                word.pop_back();
                if(word.empty()) {

                    count++;
                } else {
                    mp[word.back()].push_back(word);
                }
            }
        }
        return count;
    }
};
