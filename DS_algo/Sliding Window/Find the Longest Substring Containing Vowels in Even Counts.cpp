class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;

        vector<int> vowelCount(5, 0);

        string currentState = "00000";
        mp[currentState] = -1;

        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {

            if (s[i] == 'a')      vowelCount[0] = (vowelCount[0] + 1) % 2;
            else if (s[i] == 'e') vowelCount[1] = (vowelCount[1] + 1) % 2;
            else if (s[i] == 'i') vowelCount[2] = (vowelCount[2] + 1) % 2;
            else if (s[i] == 'o') vowelCount[3] = (vowelCount[3] + 1) % 2;
            else if (s[i] == 'u') vowelCount[4] = (vowelCount[4] + 1) % 2;

            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += to_string(vowelCount[j]);
            }

            if (stateMap.find(currentState) != mp.end()) {

                maxLength = max(maxLength, i - mp[currentState]);
            } else {

                mp[currentState] = i;
            }
        }

        return maxLength;
    }
};

class Solution {
public:
    int findTheLongestSubstring(string s) {

        unordered_map<string, int> mp;

        vector<int> state(5, 0);

        string currentState = "00000";
        mp[currentState] = -1;

        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {

            if (s[i] == 'a') state[0] ^= 1;
            else if (s[i] == 'e') state[1] ^= 1;
            else if (s[i] == 'i') state[2] ^= 1;
            else if (s[i] == 'o') state[3] ^= 1;
            else if (s[i] == 'u') state[4] ^= 1;

            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += to_string(state[j]);
            }

            if (stateMap.find(currentState) != mp.end()) {

                maxLength = max(maxLength, i - mp[currentState]);
            } else {

                mp[currentState] = i;
            }
        }

        return maxLength;
    }
};

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int mask = 0;
        mp[mask] = -1;
        int maxL = 0;
        for(int i = 0; i<s.length(); i++) {
            int val = 0;
            if (s[i] == 'a')      val  = (1 << 0);
            else if (s[i] == 'e') val = (1 << 1);
            else if (s[i] == 'i') val = (1 << 2);
            else if (s[i] == 'o') val = (1 << 3);
            else if (s[i] == 'u') val = (1 << 4);

            mask = mask^val;

            if(!mp.count(mask))
                mp[mask] = i;

            maxL = max(maxL, i - mp[mask]);
        }
        return maxL;
    }
};
