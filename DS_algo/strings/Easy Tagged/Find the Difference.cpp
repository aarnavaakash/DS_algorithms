class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;

        for(char &ch : s) {
            mp[ch]++;
        }

        for(char &ch : t) {
            mp[ch]--;

            if(mp[ch] < 0)
                return ch;
        }

        return 'a';
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;

        for (char &ch: t)
            sum += ch;

        for (char &ch: s)
            sum -=ch;

        return (char)sum;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR = 0;

        for (char &ch: t)
            XOR ^= ch;

        for (char &ch: s)
            XOR ^=ch;

        return (char)XOR;
    }
};
