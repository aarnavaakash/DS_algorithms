class Solution {
public:
    int minimumPushes(string word) {
        if(word.length() <= 8) {
            return word.length();
        }

        int count = 0;
        unordered_map<int, int> mp;

        int assign = 2;
        for(char &ch : word) {

            if(assign > 9) {
                assign = 2;
            }

            mp[assign]++;
            count += mp[assign];
            assign++;
        }

        return count;

    }
};

class Solution {
public:
    int minimumPushes(string word) {

        vector<int> mp(26, 0);
        for(char &ch: word)
            mp[ch - 'a'] = 1;

        sort(begin(mp), end(mp), greater<int>());

        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += mp[i]*((i/8) + 1);
        }
        return ans;
    }
};
