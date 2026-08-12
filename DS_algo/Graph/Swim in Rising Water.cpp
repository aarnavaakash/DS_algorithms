class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool visited[50][50];
    bool reachable(vector<vector<int>>& grid, int i, int j, int mid) {
        if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid)
            return false;

        visited[i][j] = true;

        if(i == n-1 && j == n-1)
            return true;

        for(vector<int> &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(reachable(grid, new_i, new_j, mid))
                return true;
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        int l = grid[0][0], r = n*n-1;
        int result = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;
            memset(visited, 0, sizeof(visited));

            if(reachable(grid, 0, 0, mid)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    using P = pair<int, pair<int, int>>;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;
        result[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;
            pq.pop();

            if (i == n - 1 && j == n - 1)
                return currTime;

            if (currTime > result[i][j]) continue;

            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n) {
                    int nextTime = max(currTime, grid[i_][j_]);

                    if (nextTime < result[i_][j_]) {
                        result[i_][j_] = nextTime;
                        pq.push({nextTime, {i_, j_}});
                    }
                }
            }
        }

        return -1;
    }
};
