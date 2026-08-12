class Solution {
public:
    int n;
    bool result;
    void solve(int idx, string& s1, string& s2) {
        if (idx == n) {
            if (s2.find(s1) != string::npos) {
                result = true;
            }
            return;
        }

        for (int i = idx; i < n; i++) {
            swap(s1[i], s1[idx]);

            solve(idx + 1, s1, s2);

            swap(s1[i], s1[idx]);

            if (result == true)
                return;
        }
    }

    bool checkInclusion(string s1, string s2) {
        n = s1.length();
        result = false;

        solve(0, s1, s2);

        return result;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (n > m) return false;

        string sorted_s1 = s1;
        sort(sorted_s1.begin(), sorted_s1.end());

        for (int i = 0; i <= m - n; i++) {

            string temp = s2.substr(i, n);

            sort(temp.begin(), temp.end());

            if (temp == sorted_s1) return true;
        }

        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (n > m) return false;

        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        for (int i = 0; i < n; i++) {
            s1_freq[s1[i] - 'a']++;
        }

        int i = 0;
        int j = 0;
        while (j < m) {

            s2_freq[s2[j] - 'a']++;

            if (j - i + 1 > n) {

                s2_freq[s2[i] - 'a']--;
                i++;
            }

            if (s1_freq == s2_freq) {
                return true;
            }

            j++;
        }

        return false;
    }
};
