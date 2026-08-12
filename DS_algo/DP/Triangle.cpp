class Solution {
public:
    int t[201][201];
    int n;
    int solve(vector<vector<int>>& triangle, int row, int col) {
        if (row == n-1)
            return triangle[row][col];

        if(t[row][col] != INT_MAX)
            return t[row][col];

        int minPath = triangle[row][col] +
                      min(solve(triangle, row + 1, col),
                          solve(triangle, row + 1, col + 1));

        return t[row][col] = minPath;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();

        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                t[i][j] = INT_MAX;
            }
        }
        return solve(triangle, 0, 0);
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> t = triangle;

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                t[row][col] += min(t[row + 1][col], t[row + 1][col + 1]);
            }
        }

        return t[0][0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> t = triangle.back();

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                t[col] = triangle[row][col] + min(t[col], t[col + 1]);
            }
        }

        return t[0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> t(n, 0);

        t[0] = triangle[0][0];

        for (int row = 1; row < n; row++) {

            for (int col = row; col >= 0; col--) {
                if (col == 0) {
                    t[col] = t[col] + triangle[row][col];
                } else if (col == row) {
                    t[col] = t[col - 1] + triangle[row][col];
                } else {
                    t[col] = min(t[col], t[col - 1]) + triangle[row][col];
                }
            }
        }

        return *min_element(t.begin(), t.end());
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for(int row = 1; row < n; row++) {
            for(int col = 0; col<triangle[row].size(); col++) {
                int prev_up_val  = triangle[row-1][min(col, (int)triangle[row-1].size()-1)];
                int prev_up_left = triangle[row-1][max(col-1, 0)];

                triangle[row][col] += min(prev_up_val, prev_up_left);
            }
        }

        return *min_element(triangle[n-1].begin(), triangle[n-1].end());

    }
};
