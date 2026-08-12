class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jobDifficulty, int n, int idx, int d) {

        if (d == 1) {
            return *max_element(begin(jobDifficulty) + idx, end(jobDifficulty));
        }

        if (t[idx][d] != -1)
            return t[idx][d];

        int Max = INT_MIN;
        int result = INT_MAX;

        for (int i = idx; i <= n - d; i++) {
            Max = max(Max, jobDifficulty[i]);
            result = min(result, Max + solve(jobDifficulty, n, i + 1, d - 1));
        }

        return t[idx][d] = result;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        memset(t, -1, sizeof(t));

        return solve(jobDifficulty, n, 0, d);
    }
};

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        vector<vector<int>> t(n+1, vector<int>(d+1, -1));

        for (int i = 0; i < n; i++) {
            t[i][1] = *max_element(begin(jobDifficulty) + i, end(jobDifficulty));
        }

        for (int days = 2; days <= d; days++) {
            for (int i = 0; i <= n - days; i++) {
                int maxDifficulty = INT_MIN;
                int result        = INT_MAX;

                for (int j = i; j <= n - days; j++) {
                    maxDifficulty   = max(maxDifficulty, jobDifficulty[j]);
                    result          = min(result, maxDifficulty + t[j + 1][days - 1]);
                }

                t[i][days] = result;
            }
        }

        return t[0][d];
    }
};
