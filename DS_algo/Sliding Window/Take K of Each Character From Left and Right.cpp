class Solution {
public:

    int result = INT_MAX;

    void solve(string& s, int k, int i, int j, int minutes, vector<int> freq) {
        if(freq[0] >= k && freq[1] >= k && freq[2] >= k) {
            result = min(result, minutes);
            return;
        }
        if(i > j)
            return;

        vector<int> tempFreqLeft = freq;
        tempFreqLeft[s[i] - 'a'] += 1;
        solve(s, k, i+1, j, minutes+1, tempFreqLeft);

        vector<int> tempFreqRight = freq;
        tempFreqRight[s[j] - 'a'] += 1;
        solve(s, k, i, j-1, minutes+1, tempFreqRight);

    }

    int takeCharacters(string s, int k) {
        vector<int> freq(3, 0);
        int i = 0;
        int j = s.length()-1;
        int minutes = 0;
        solve(s, k, i, j, minutes, freq);

        return result == INT_MAX ? -1 : result;
    }
};

class Solution {
public:

    int takeCharacters(string s, int k) {
        int n = s.length();

        int count_a = 0;
        int count_b = 0;
        int count_c = 0;
        for(char &ch : s) {
            if(ch == 'a')
                count_a++;
            else if(ch == 'b')
                count_b++;
            else
                count_c++;
        }

        if(count_a < k || count_b < k || count_c < k) {
            return -1;
        }

        int i = 0;
        int j = 0;
        int notDeletedWindowSize = 0;

        while(j < n) {
            if(s[j] == 'a') {
                count_a--;
            } else if(s[j] == 'b') {
                count_b--;
            } else if(s[j] == 'c') {
                count_c--;
            }

            while(i <= j && (count_a < k || count_b < k || count_c < k)) {

                if(s[i] == 'a') {
                    count_a++;
                } else if(s[i] == 'b') {
                    count_b++;
                } else {
                    count_c++;
                }
                i++;
            }

            notDeletedWindowSize = max(notDeletedWindowSize, j-i+1);
            j++;
        }

        return n - notDeletedWindowSize;

    }
};

class Solution {
    private int result = Integer.MAX_VALUE;

    private void solve(String s, int k, int i, int j, int minutes, int[] freq) {
        if (freq[0] >= k && freq[1] >= k && freq[2] >= k) {
            result = Math.min(result, minutes);
            return;
        }
        if (i > j)
            return;

        int[] tempFreqLeft = freq.clone();
        tempFreqLeft[s.charAt(i) - 'a']++;
        solve(s, k, i + 1, j, minutes + 1, tempFreqLeft);

        int[] tempFreqRight = freq.clone();
        tempFreqRight[s.charAt(j) - 'a']++;
        solve(s, k, i, j - 1, minutes + 1, tempFreqRight);
    }

    public int takeCharacters(String s, int k) {
        int[] freq = new int[3];
        int i = 0;
        int j = s.length() - 1;
        int minutes = 0;
        solve(s, k, i, j, minutes, freq);

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}

class Solution {
    public int takeCharacters(String s, int k) {
        int n = s.length();

        int countA = 0, countB = 0, countC = 0;
        for (char ch : s.toCharArray()) {
            if (ch == 'a') countA++;
            else if (ch == 'b') countB++;
            else if (ch == 'c') countC++;
        }

        if (countA < k || countB < k || countC < k) {
            return -1;
        }

        int i = 0, j = 0;
        int notDeletedWindowSize = 0;

        while (j < n) {

            if (s.charAt(j) == 'a') {
                countA--;
            } else if (s.charAt(j) == 'b') {
                countB--;
            } else if (s.charAt(j) == 'c') {
                countC--;
            }

            while (i <= j && (countA < k || countB < k || countC < k)) {
                if (s.charAt(i) == 'a') {
                    countA++;
                } else if (s.charAt(i) == 'b') {
                    countB++;
                } else if (s.charAt(i) == 'c') {
                    countC++;
                }
                i++;
            }

            notDeletedWindowSize = Math.max(notDeletedWindowSize, j - i + 1);
            j++;
        }

        return n - notDeletedWindowSize;
    }
}
