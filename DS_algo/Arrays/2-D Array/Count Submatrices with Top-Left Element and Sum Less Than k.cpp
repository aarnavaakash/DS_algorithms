class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int sum = 0;
                for (int m1 = 0; m1 <= i; m1++) {
                    for (int n1 = 0; n1 <= j; n1++) {
                        sum += grid[m1][n1];
                    }
                }

                if (sum <= k) count++;
            }
        }

        return count;
    }
};

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if (i > 0)
                  grid[i][j] += grid[i - 1][j];
                if (j > 0)
                  grid[i][j] += grid[i][j - 1];
                if (i > 0 && j > 0)
                  grid[i][j] -= grid[i - 1][j - 1];

                if(grid[i][j] <= k)
                    count++;
                else
                    break;
            }
        }

        return count;
    }
};
