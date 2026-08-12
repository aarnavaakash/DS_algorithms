class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(begin(s), end(s));
        sort(begin(t), end(t));

        return s == t;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);

        for(char &ch : s) {
            count[ch-'a']++;
        }

        for(char &ch : t) {
            count[ch-'a']--;
        }

        bool allZeros = all_of(begin(count), end(count), [](int element) {
            return element == 0;
        });

        return allZeros;
    }
};
