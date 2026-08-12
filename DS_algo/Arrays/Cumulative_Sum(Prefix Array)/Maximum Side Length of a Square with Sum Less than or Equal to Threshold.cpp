class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = mat[i][j]
                             + (i > 0 ? prefix[i - 1][j] : 0)
                             + (j > 0 ? prefix[i][j - 1] : 0)
                             - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        auto sumSquare = [&](int i, int j, int r2, int c2) {
            int sum = prefix[r2][c2];
                    if (i > 0) sum -= prefix[i - 1][c2];
                    if (j > 0) sum -= prefix[r2][j - 1];
                    if (i > 0 && j > 0) sum += prefix[i - 1][j - 1];

            return sum;
        };

        int best = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = best; k < min(rows - i, cols - j); k++) {

                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = sumSquare(i, j, r2, c2);

                    if (sum <= threshold) {
                        best = k + 1;
                    } else {
                        break;
                    }
                }
            }
        }

        return best;
    }
};

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = mat[i][j]
                             + (i > 0 ? prefix[i - 1][j] : 0)
                             + (j > 0 ? prefix[i][j - 1] : 0)
                             - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        auto sumSquare = [&](int r1, int c1, int r2, int c2) {
            int sum = prefix[r2][c2];
            if (r1 > 0) sum -= prefix[r1 - 1][c2];
            if (c1 > 0) sum -= prefix[r2][c1 - 1];
            if (r1 > 0 && c1 > 0) sum += prefix[r1 - 1][c1 - 1];
            return sum;
        };

        auto check = [&](int side) {
            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {
                    if (sumSquare(i, j,
                                  i + side - 1,
                                  j + side - 1) <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };

        int lo = 1, hi = min(rows, cols);
        int result = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                result = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return result;
    }
};
