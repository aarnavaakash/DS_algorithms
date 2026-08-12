class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> count;

        for (string& word : words) {
            for (char &ch : word) {
                count[ch]++;
            }
        }

        for (auto &it : count) {
            if (it.second % n != 0) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        int count[26] = {0};

        for(string &word : words) {

            for(char &ch : word) {
                count[ch-'a']++;
            }

        }

        for(int i = 0; i < 26; i++) {
            if(count[i]%n != 0) {
                return false;
            }
        }

        return true;

    }
};

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int count[26] = {0};

        for (string &word : words) {
            for (char &ch : word) {
                ++count[ch - 'a'];
            }
        }

        auto lambda = [&](int c) {
                   return c % n == 0;
        };

        return all_of(begin(count), end(count), lambda);

    }
};
