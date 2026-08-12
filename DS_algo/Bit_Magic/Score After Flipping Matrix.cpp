class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) {

                for(int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }

            }
        }

        for(int j = 1; j < n; j++) {

            int countZero = 0;
            for(int i = 0; i < m; i++) {
                if(grid[i][j] == 0) {
                    countZero++;
                }
            }

            int countOne = m - countZero;
            if(countZero > countOne) {

                for(int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }

        }

        int score = 0;
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                int value = grid[i][j] * pow(2, n-j-1);

                score += value;

            }

        }

        return score;

    }
};

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int score = pow(2, n-1) * m;

        for(int j = 1; j < n; j++) {

            int countSameBits = 0;
            for(int i = 0; i < m; i++) {
                if(grid[i][j] == grid[i][0]) {
                    countSameBits++;
                }
            }

            int countOnes  = countSameBits;
            int countZeros = m - countOnes;

            int ones = max(countOnes, countZeros);

            score += (pow(2, n-j-1) * ones);

        }

        return score;

    }
};
