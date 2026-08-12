class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> result;
        unordered_map<string, int> unique_substr;

        for (string& str : arr) {

            unordered_set<string> seen;

            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {

                    string substring = str.substr(i, j - i);
                    if (seen.find(substring) == seen.end()) {
                        unique_substr[substring]++;
                        seen.insert(substring);
                    }

                }
            }
        }
        for (const string& str : arr) {
            string shortest = "";

            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {

                    string substring = str.substr(i, j - i);

                    if (unique_substr[substring] == 1 &&
                        (shortest == "" || substring.length() < shortest.length()
                        || (substring.length() == shortest.length() && substring < shortest))) {

                        shortest = substring;

                    }

                }
            }

            result.push_back(shortest);
        }
        return result;
    }
};
