class Solution {
public:

    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) {
            return true;
        }

        if(grid2[i][j] != 1) {
            return true;
        }

        grid2[i][j] = -1;

        bool result = (grid1[i][j] == 1);

        result = result & checkSubIsland(grid1, grid2, i+1, j);
        result = result & checkSubIsland(grid1, grid2, i-1, j);
        result = result & checkSubIsland(grid1, grid2, i, j+1);
        result = result & checkSubIsland(grid1, grid2, i, j-1);

        return result;

    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int subIslands = 0;
        int m = grid2.size();
        int n = grid2[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) {
                    subIslands++;
                }
            }
        }

        return subIslands;
    }
};

class Solution {
public:

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid1.size();
        int n = grid1[0].size();

        bool result = true;

        queue<pair<int, int>> que;
        que.push({i, j});
        grid2[i][j] = -1;

        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            if(grid1[x][y] != 1) {
                result = false;
            }

            for(vector<int>& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1) {
                    grid2[newX][newY] = -1;
                    que.push({newX, newY});
                }
            }
        }

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int subIslands = 0;
        int m = grid2.size();
        int n = grid2[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) {
                    subIslands++;
                }
            }
        }

        return subIslands;
    }
};
