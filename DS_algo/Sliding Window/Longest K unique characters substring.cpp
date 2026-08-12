class Solution{
    public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int maxLen = -1;
        while(j < n) {
            mp[s[j]]++;

            if(mp.size() == k) {
                maxLen = max(maxLen, j-i+1);
            } else if(mp.size() > k) {
                while(mp.size() > k) {
                    mp[s[i]]--;
                    if(mp[s[i]] <= 0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxLen;
    }
};
