class Solution {
public:
    int ans = 0;
    int n;

    void findMax(string answerKey) {
        int length = 0;

        int i = 0;

        while(i < n) {

            if(answerKey[i] == 'T') {
                length = 1;
                i++;
                while(i < n && answerKey[i] == 'T') {
                    length++;
                    i++;
                }
                ans = max(ans, length);
            } else {
                length = 1;
                i++;
                while(i < n && answerKey[i] == 'F') {
                    length++;
                    i++;
                }
                ans = max(ans, length);
            }

        }
    }

    void solve(int idx, string &answerKey, int k) {

        findMax(answerKey);

        if(idx >= n || k <= 0) {
            return;
        }

        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T';

        solve(idx+1, answerKey, k-1);

        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T';
        solve(idx+1, answerKey, k);

    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.length();

        solve(0, answerKey, k);

        return ans;
    }
};

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int result = 0;

        int i = 0, j = 0;
        int countF = 0;
        while(j < n) {
            if(answerKey[j] == 'F')
                countF++;

            while(countF > k) {
                if(answerKey[i] == 'F')
                    countF--;
                i++;
            }

            result = max(result, j-i+1);

            j++;
        }

        i = 0, j = 0;
        int countT = 0;
        while(j < n) {
            if(answerKey[j] == 'T')
                countT++;

            while(countT > k) {
                if(answerKey[i] == 'T')
                    countT--;
                i++;
            }

            result = max(result, j-i+1);
            j++;
        }

        return result;
    }

};

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int result = k;

        unordered_map<char, int> mp;

        int i = 0;
        for (int j = 0; j < answerKey.length(); j++) {

            mp[answerKey[j]]++;

            while (min(mp['T'], mp['F']) > k) {
                mp[answerKey[i]]--;
                i++;
            }

            result = max(result, j - i + 1);
        }

        return result;
    }
};
