class Solution {
public:
    long M = 1e9 + 7;
    int t[31][1001];
    int solve(int n, int k, int target) {
        if(target < 0 || n == 0)
            return target == 0 ? 1 : 0;

        if(t[n][target] != -1)
            return t[n][target];

        int sum = 0;

        for(int i = 1; i <= k; i++) {
            sum  = sum + solve(n-1, k, target-i);
            sum %= M;
        }

        return t[n][target] = sum;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(t, -1, sizeof(t));
        return solve(n, k, target);
    }
};

class Solution {
public:
    long M = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> t(n+1, vector<int>(target+1));

        t[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j<= target; j++) {

                for(int f = 1; f <= k; f++) {

                    if(f <= j) {
                        t[i][j] = (t[i][j] + t[i-1][j-f])%M;
                    }
                }
            }
        }

        return t[n][target];

    }
};
