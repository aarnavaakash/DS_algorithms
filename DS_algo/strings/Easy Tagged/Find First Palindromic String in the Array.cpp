class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for(string &word : words) {
            if(word == string(rbegin(word), rend(word))) {
                return word;
            }
        }

        return "";

    }
};

class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for(string &word : words) {
            if(equal(word.begin(), word.begin() + word.size() / 2, word.rbegin())) {
                return word;
            }
        }

        return "";

    }
};
