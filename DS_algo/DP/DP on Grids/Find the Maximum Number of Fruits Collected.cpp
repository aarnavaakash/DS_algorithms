class Solution {
    int n;
    vector<vector<int>> t;

public:

    int child1Collect(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += grid[i][i];
            grid[i][i] = 0;
            t[i][i] = 0;
        }
        return ans;
    }

    int child2Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }

        if (i == j || i > j) {
            return 0;
        }

        if (t[i][j] != -1)
            return t[i][j];

        int leftcorner = grid[i][j] + child2Collect(i + 1, j - 1, grid);
        int middle = grid[i][j] + child2Collect(i + 1, j, grid);
        int rightcorner = grid[i][j] + child2Collect(i + 1, j + 1, grid);

        return t[i][j] = max({middle, rightcorner, leftcorner});
    }

    int child3Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }

        if (i == j || j > i) {
            return 0;
        }
        if (t[i][j] != -1)
            return t[i][j];

        int topcorner   = grid[i][j] + child3Collect(i - 1, j + 1, grid);
        int right       = grid[i][j] + child3Collect(i, j + 1, grid);
        int rightcorner = grid[i][j] + child3Collect(i + 1, j + 1, grid);

        return t[i][j] = max({right, rightcorner, topcorner});
    }

    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();
        t.resize(n, vector<int>(n, -1));

        int firstChildScore = child1Collect(grid);

        int secondChildScore = child2Collect(0, n - 1, grid);

        int thirdChildScore  = child3Collect(n - 1, 0, grid);

        return (firstChildScore + secondChildScore + thirdChildScore);
    }
};

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> t(n, vector<int>(n, 0));

        int result = 0;
        for(int i = 0; i < n; i++) {
            result += fruits[i][i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i < j && i+j < n-1) {
                    t[i][j] = 0;
                } else if(i > j && i+j < n-1) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = fruits[i][j];
                }
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                t[i][j] += max({t[i-1][j-1], t[i-1][j], (j+1 < n) ? t[i-1][j+1] : 0});
            }
        }

        for(int j = 1; j < n; j++) {
            for(int i = j+1; i < n; i++) {
                t[i][j] += max({t[i-1][j-1], t[i][j-1], (i+1 < n) ? t[i+1][j-1] : 0});
            }
        }

        return result + t[n-2][n-1] + t[n-1][n-2];

    }
};
