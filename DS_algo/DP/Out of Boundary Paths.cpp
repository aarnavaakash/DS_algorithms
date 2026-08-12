class Solution {
public:
    int M;
    int N;
    int MOD = 1e9+7;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int t[51][51][51];
    int solve(int maxMove, int startRow, int startColumn) {
        if(startRow < 0 || startRow >= M || startColumn < 0 || startColumn >= N) {
            return 1;
        }

        if(maxMove <= 0)
            return 0;

        if(t[maxMove][startRow][startColumn] != -1) {
            return t[maxMove][startRow][startColumn];
        }

        int result = 0;
        for(auto &dir : directions) {
            int x = startRow    + dir[0];
            int y = startColumn + dir[1];

            result = (result + solve(maxMove-1, x, y)) % MOD;
        }

        return t[maxMove][startRow][startColumn] = result%MOD;

    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t, -1, sizeof(t));
        M = m;
        N = n;
        return solve(maxMove, startRow, startColumn);
    }
};

class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        int dp[50][50][51];

        memset(dp, 0, sizeof(dp));

        for (int k = 1; k <= maxMove; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {

                    for(auto &dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x < 0 || x >= m || y < 0 || y >= n)
                            dp[i][j][k] = (dp[i][j][k] + 1) % MOD;
                        else
                            dp[i][j][k] = (dp[i][j][k] + dp[x][y][k - 1]) % MOD;

                    }
                }
            }
        }

        return dp[startRow][startColumn][maxMove];

    }
};

class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        vector<vector<int>> t(50, vector<int>(50));
        t[startRow][startColumn] = 1;
        int result = 0;

        for (int k = 1; k <= maxMove; ++k) {
            vector<vector<int>> temp(50, vector<int>(50));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {

                    for(auto &dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            result = (result + t[i][j]) % MOD;
                        }
                        else {
                            temp[x][y] = (temp[x][y] + t[i][j]) % MOD;
                        }
                    }
                }
            }
            t = temp;
        }

        return result;

    }
};
