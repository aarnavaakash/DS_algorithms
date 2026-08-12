class Solution {
public:
    vector<vector<int>> result;
    bool isPalindrome(string &key) {
        int i = 0, j = key.length()-1;

        while(i < j) {
            if(key[i] != key[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        result.clear();

        unordered_map<string, int> mp;
        int n = words.size();

        for(int i = 0; i<n; i++) {
            mp[words[i]] = i;
        }

        if(mp.find("") != mp.end()) {
            int emptyIndex = mp[""];

            for(int i = 0; i<n; i++) {
                if(i != emptyIndex && isPalindrome(words[i])) {
                    result.push_back({emptyIndex, i});
                    result.push_back({i, emptyIndex});
                }
            }
        }

        for(int i = 0; i<n; i++) {
            string word      = words[i];
            reverse(begin(word), end(word));

            if(mp.find(word) != mp.end() && mp[word] != i) {
                result.push_back({i, mp[word]});

            }
        }

        for(int i = 0; i<n; i++) {
            string word = words[i];

            for(int cut = 1; cut<word.length(); cut++) {
                string leftHalf         = word.substr(0, cut);
                string rightHalf        = word.substr(cut);

                string reverseLeftHalf  = leftHalf;
                reverse(begin(reverseLeftHalf), end(reverseLeftHalf));

                string reverseRightHalf  = rightHalf;
                reverse(begin(reverseRightHalf), end(reverseRightHalf));

                if(isPalindrome(leftHalf) && mp.find(reverseRightHalf) != mp.end()) {
                    result.push_back({mp[reverseRightHalf], i});
                }

                if(isPalindrome(rightHalf) && mp.find(reverseLeftHalf) != mp.end()) {
                    result.push_back({i, mp[reverseLeftHalf]});
                }
            }
        }

        return result;
    }
};
