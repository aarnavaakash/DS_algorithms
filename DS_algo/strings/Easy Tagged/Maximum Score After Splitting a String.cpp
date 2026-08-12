class Solution {
public:
    int maxScore(string s) {
        int n = s.length();

        int result = INT_MIN;

        for(int i = 0; i < n-1; i++) {

            int zeros_left = 0;
            for(int j = 0; j <= i; j++) {
                if(s[j] == '0') {
                    zeros_left++;
                }
            }

            int ones_right = 0;
            for(int j = i+1; j < n; j++) {
                if(s[j] == '1') {
                    ones_right++;
                }
            }

            result = max(result, zeros_left + ones_right);

        }

        return result;
    }
};

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = INT_MIN;
        int total_ones = count(begin(s), end(s), '1');

        int zeros = 0;

        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1') {
                total_ones--;
            } else {
                zeros++;
            }

            result = max(result, zeros + total_ones);
        }

        return result;
    }
};

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = INT_MIN;

        int zeros = 0;
        int ones  = 0;

        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }

            result = max(result, zeros - ones);
        }

        if(s[n-1] == '1') {
            ones++;
        }

        return result+ones;
    }
};
