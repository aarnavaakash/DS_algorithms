class Solution {
public:
    vector<string> result;

    void solve(string &curr, string &s, int idx) {

        if (idx == s.length()) {

            if (curr != "") {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back(s[idx]);
        solve(curr, s, idx + 1);

        curr.pop_back();
        solve(curr, s, idx + 1);
    }

    vector<string> AllPossibleStrings(string s) {
        string curr = "";

        solve(curr, s, 0);

        sort(begin(result), end(result));

        return result;
    }
};

class Solution {
public:
    vector<string> result;

    void solve(string &curr, string &s, int idx) {

        if (curr != "") {
            result.push_back(curr);
        }

        for (int i = idx; i < s.length(); i++) {

            curr.push_back(s[i]);
            solve(curr, s, i + 1);
            curr.pop_back();
        }
    }

    vector<string> AllPossibleStrings(string s) {
        string curr = "";
        solve(curr, s, 0);
        sort(begin(result), end(result));
        return result;
    }
};
