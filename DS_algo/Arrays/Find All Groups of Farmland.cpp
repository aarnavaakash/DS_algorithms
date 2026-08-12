class Solution {
public:
    int m;
    int n;
    vector<vector<int>> result;

    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2) {
        land[i][j] = 0;

        r2 = max(r2, i);
        c2 = max(c2, j);

        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1) {
                dfs(land, i_, j_, r2, c2);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;

                    dfs(land, i, j, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }

            }
        }

        return result;
    }
};

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> result;

    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void bfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2) {
        queue<pair<int, int>> que;
        que.push({i, j});

        while(!que.empty()) {

            pair<int, int> p = que.front();
            que.pop();

            r2 = max(r2, p.first);
            c2 = max(c2, p.second);

            for(auto &dir : directions) {
                int i_ = p.first  + dir[0];
                int j_ = p.second + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1) {
                    land[i_][j_] = 0;
                    que.push({i_, j_});
                }
            }

        }

    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;

                    bfs(land, i, j, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }

            }
        }

        return result;
    }
};

class Solution {
public:

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> result;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(land[i][j] == 0) continue;

                int c1 = j;
                while(c1 < n && land[i][c1] == 1) {
                    c1++;
                }

                int r1 = i;
                while(r1 < m && land[r1][j] == 1) {
                    r1++;
                }

                c1 = c1 == 0 ?  c1 : c1-1;
                r1 = r1 == 0 ?  r1 : r1-1;

                result.push_back({i, j, r1, c1});

                for(int k = i; k <= r1; k++) {
                    for(int l = j; l <= c1; l++) {
                        land[k][l] = 0;
                    }
                }

            }
        }

        return result;

    }
};
