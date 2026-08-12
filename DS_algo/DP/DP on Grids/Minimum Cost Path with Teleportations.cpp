class Solution {
public:
    int m, n, K;

    vector<vector<vector<int>>> t;

    int solve(int i, int j, int tPort, vector<vector<int>>& grid) {

        if (i == m - 1 && j == n - 1)
            return 0;

        if (t[i][j][tPort] != -1)
            return t[i][j][tPort];

        int result = 1e9;
        int curVal = grid[i][j];

        if (j + 1 < n) {
            int next = solve(i, j + 1, tPort, grid);
            result = min(result, grid[i][j + 1] + next);
        }

        if (i + 1 < m) {
            int next = solve(i + 1, j, tPort, grid);
            result = min(result, grid[i + 1][j] + next);
        }

        if (tPort < K) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if ((x != i || y != j) && grid[x][y] <= curVal) {
                        result = min(result, solve(x, y, tPort + 1, grid));
                    }
                }
            }
        }

        return t[i][j][tPort] = result;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        K = k;
        m = grid.size();
        n = grid[0].size();

        t.assign(m, vector<vector<int>>(n, vector<int>(K + 1, -1)));

        return solve(0, 0, 0, grid);
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;

        vector<vector<vector<int>>> t(
            m, vector<vector<int>>(n, vector<int>(k + 1, INF))
        );

        for (int tPort = 0; tPort <= k; tPort++) {
            t[m - 1][n - 1][tPort] = 0;
        }

        for (int tPort = k; tPort >= 0; tPort--) {
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {

                    if (i == m - 1 && j == n - 1)
                        continue;

                    int result = 1e9;

                    if (j + 1 < n) {
                        result = min(result,
                                     grid[i][j + 1] + t[i][j + 1][tPort]);
                    }

                    if (i + 1 < m) {
                        result = min(result,
                                     grid[i + 1][j] + t[i + 1][j][tPort]);
                    }

                    if (tPort < k) {
                        for (int x = 0; x < m; x++) {
                            for (int y = 0; y < n; y++) {
                                if ((x != i || y != j) && grid[x][y] <= grid[i][j]) {
                                    result = min(result, t[x][y][tPort + 1]);
                                }
                            }
                        }
                    }

                    t[i][j][tPort] = result;
                }
            }
        }

        return t[0][0][0];
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[m-1][n-1] = 0;

        int maxVal = 0;
        for(auto &row : grid) {
            for(int &val : row) {
                maxVal = max(maxVal, val);
            }
        }

        vector<int> teleportCost(maxVal+1, INT_MAX);

        for(int t = 0; t <= k; t++) {

            for(int i = m-1; i >= 0; i--) {
                for(int j = n-1; j >= 0; j--) {

                    if(i+1 < m)
                        dp[i][j] = min(dp[i][j], grid[i+1][j] + dp[i+1][j]);

                    if(j+1 < n)
                        dp[i][j] = min(dp[i][j], grid[i][j+1] + dp[i][j+1]);

                    if(t > 0) {
                        dp[i][j] = min(dp[i][j], teleportCost[grid[i][j]]);
                    }
                }
            }

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    teleportCost[grid[i][j]] = min(teleportCost[grid[i][j]], dp[i][j]);
                }
            }

            for(int i = 1; i < teleportCost.size(); i++) {
                teleportCost[i] = min(teleportCost[i], teleportCost[i-1]);
            }
        }

        return dp[0][0];
    }
};
