class Solution {
public:
    bool doesAliceWin(string s) {

        for(char &ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool doesAliceWin(string s) {
        auto lambda = [](char ch) {
            return string("aeiou").find(ch) != string::npos;
        };

        return any_of(s.begin(), s.end(), lambda);
    }
};
