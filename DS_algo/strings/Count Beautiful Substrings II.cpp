class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int vowels = 0;
            int consonants = 0;

            for (int j = i; j < n; j++) {
                if (isVowel(s[j])) {
                    vowels++;
                } else {
                    consonants++;
                }

                if (vowels == consonants && (vowels * consonants) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    #define ll long long

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long beautifulSubstrings(string s, int k) {
        ll vowel = 0;
        ll consonant = 0;

        ll result = 0;

        unordered_map<ll, unordered_map<ll, ll>> mp;
        mp[0][0] = 1;

        for(char &ch : s) {

            if(isVowel(ch)) {
                vowel++;
            } else {
                consonant++;
            }

            ll pSum = (vowel - consonant);

            for(auto &[pastVowelCount, count] : mp[pSum]) {

                if((vowel%k - pastVowelCount) * (vowel%k - pastVowelCount) % k == 0) {
                    result += count;
                }

            }

            mp[pSum][vowel%k]++;
        }

        return result;
    }
};
