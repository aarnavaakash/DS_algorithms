class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 0;
        }
    }

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) {
            return;
        }

        if(size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }

    void setSize(int x, int fishCount) {
        size[x] = fishCount;
    }

    int getMaxFishCount() {
        return *max_element(begin(size), end(size));
    }
};

class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalCells = m*n;

        DSU dsu(totalCells);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int idx = i*n + j;
                    dsu.setSize(idx, grid[i][j]);
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int idx = i * n + j;
                    for(auto &dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                            int idx_ = i_ * n + j_;
                            dsu.Union(idx, idx_);
                        }
                    }
                }
            }
        }

        return dsu.getMaxFishCount();

    }
};

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        que.push({i, j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;

        while(!que.empty()) {
            i = que.front().first;
            j = que.front().second;
            que.pop();

            for(auto &dir : directions) {
                int i_ = dir[0] + i;
                int j_ = dir[1] + j;

                if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n && grid[i_][j_] > 0) {
                    que.push({i_, j_});
                    fishCount += grid[i_][j_];
                    grid[i_][j_] = 0;
                }
            }
        }

        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxFish = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)  {
                if(grid[i][j] > 0) {
                    maxFish = max(maxFish, bfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int fishCount = grid[i][j];
        grid[i][j] = 0;

        for(vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            fishCount += dfs(i_, j_, grid);
        }

        return fishCount;

    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxFish = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)  {
                if(grid[i][j] > 0) {
                    maxFish = max(maxFish, dfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};
