class Solution {
public:

    void markGaurded(int row, int col, vector<vector<int>>& grid) {

        for(int i = row-1; i >= 0; i--) {
            if(grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1;
        }

        for(int i = row+1; i < grid.size(); i++) {
            if(grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1;
        }

        for(int j = col-1; j >= 0; j--) {
            if(grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            grid[row][j] = 1;
        }

        for(int j = col+1; j < grid[0].size(); j++) {
            if(grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            grid[row][j] = 1;
        }

    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(vector<int>& vec : guards) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2;
        }

        for(vector<int>& vec : walls) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3;
        }

        for(vector<int>& gaurd : guards) {
            int i = gaurd[0];
            int j = gaurd[1];
            markGaurded(i, j, grid);
        }

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;

    }
};

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols, int direction) {

        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 1 || grid[row][col] == 2) {
            return;
        }

        grid[row][col] = 3;

        if (direction == 1) {
            dfs(grid, row - 1, col, rows, cols, direction);
        } else if (direction == 2) {
            dfs(grid, row + 1, col, rows, cols, direction);
        } else if (direction == 3) {
            dfs(grid, row, col - 1, rows, cols, direction);
        } else {
            dfs(grid, row, col + 1, rows, cols, direction);
        }
    }

    int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>> grid(rows, vector<int>(cols, 0));

        for (const auto& guard : guards) {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 1;
        }

        for (const auto& wall : walls) {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 2;
        }

        for (const auto& guard : guards) {
            int guardRow = guard[0];
            int guardCol = guard[1];

            dfs(grid, guardRow - 1, guardCol, rows, cols, 1);
            dfs(grid, guardRow + 1, guardCol, rows, cols, 2);
            dfs(grid, guardRow, guardCol - 1, rows, cols, 3);
            dfs(grid, guardRow, guardCol + 1, rows, cols, 4);
        }

        int unguardedCount = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }
};
