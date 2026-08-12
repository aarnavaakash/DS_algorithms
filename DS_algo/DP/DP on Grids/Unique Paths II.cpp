class Solution {
public:
    int m, n;
    int t[101][101];

    int solve(vector<vector<int>>& obstacleGrid, int i, int j) {

        if(i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }

        if(t[i][j] != -1)
            return t[i][j];

        if(i == m-1 && j == n-1)
            return 1;

        int right = solve(obstacleGrid, i, j+1);
        int down  = solve(obstacleGrid, i+1, j);

        return t[i][j] = right + down;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        memset(t, -1, sizeof(t));

        return solve(obstacleGrid, 0, 0);
    }
};

class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> t(m, vector<int>(n, 0));
        if(obstacleGrid[0][0] == 1)
            return 0;

        for(int col = 0; col<n; col++) {
            if(col > 0 && obstacleGrid[0][col-1] == 1) {
                t[0][col] = 0;
                obstacleGrid[0][col] = 1;
            }
            else if(obstacleGrid[0][col] == 1)
                t[0][col] = 0;
            else
                t[0][col] = 1;
        }

        for(int row = 0; row<m; row++) {
            if(row > 0 && obstacleGrid[row-1][0] == 1) {
                t[row][0] = 0;
                obstacleGrid[row][0] = 1;
            }
            else if(obstacleGrid[row][0] == 1)
                t[row][0] = 0;
            else
                t[row][0] = 1;
        }

        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                if(obstacleGrid[i][j] == 1)
                    t[i][j] = 0;
                else
                    t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        return solve(obstacleGrid);

    }
};

************************************************************ JAVA ************************************************************

class Solution {
    Integer t[][]=new Integer[101][101];
    int m, n;

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        m = obstacleGrid.length;
        n = obstacleGrid[0].length;

        return solve(obstacleGrid, 0, 0);
    }
    int solve(int[][]obstacleGrid, int i, int j){
         if(i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }

        if(t[i][j] != null)
            return t[i][j];

        if(i == m-1 && j == n-1)
            return 1;

        int right = solve(obstacleGrid, i, j+1);
        int down  = solve(obstacleGrid, i+1, j);

        return t[i][j] = right + down;
    }
}
