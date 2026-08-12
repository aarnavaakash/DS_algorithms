class Solution {
public:

    void LPS(string &word, vector<int>& lps, int n) {
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while(i < n) {
            if(word[i] == word[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();

        vector<int> lps(n);
        LPS(word, lps, n);

        int maxLps = lps[n-1];

        while(maxLps > 0 && (n-maxLps)%k != 0) {
            maxLps = lps[maxLps-1];
        }

        if((n-maxLps)%k == 0) {
            return (n-maxLps)/k;
        }

        return ceil(n/(double)k);
    }
};
