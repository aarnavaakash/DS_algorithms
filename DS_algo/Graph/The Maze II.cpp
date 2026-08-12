class Solution {
public:
    int end_x, end_y;
    int m, n;
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int t[101][101];

    void DFS(vector<vector<int>> &maze, int x, int y) {

        for(pair<int, int> &dir : directions) {
            int steps = 0;
            int x_ = x;
            int y_ = y;

            while(x_ >=  0 && x_ < m && y_ >= 0 && y_ < n && maze[x_][y_] == 0) {
                x_ += dir.first;
                y_ += dir.second;
                steps++;
            }

            x_ -= dir.first;
            y_ -= dir.second;
            steps--;

            if(t[x][y] + steps < t[x_][y_]) {
                t[x_][y_] = t[x][y] + steps;
                DFS(maze, x_, y_);
            }
        }

    }

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        end_x = destination[0];
        end_y = destination[1];
        m = maze.size();
        n = maze[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                t[i][j]  = INT_MAX;
            }
        }

        t[start[0]][start[1]] = 0;
        DFS(maze, start[0], start[1]);

        return t[end_x][end_y] == INT_MAX ? -1 : t[end_x][end_y];

    }
};

class Solution {
public:
    int end_x, end_y;
    int m, n;
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int t[101][101];

    int BFS(vector<vector<int>> &maze, int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});

        while(!que.empty()) {
            pair<int, int> curr = que.front();
            que.pop();

            for(pair<int, int> &dir : directions) {
                int x_    = curr.first;
                int y_    = curr.second;
                int steps = 0;
                while(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && maze[x_][y_] == 0) {
                    x_ += dir.first;
                    y_ += dir.second;
                    steps++;
                }

                x_ -= dir.first;
                y_ -= dir.second;
                steps--;

                if(t[curr.first][curr.second] + steps < t[x_][y_]) {
                    t[x_][y_] = t[curr.first][curr.second] + steps;
                    que.push({x_, y_});
                }

            }
        }
    }

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        end_x = destination[0];
        end_y = destination[1];
        m = maze.size();
        n = maze[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                t[i][j]  = INT_MAX;
            }
        }

        t[start[0]][start[1]] = 0;
        BFS(maze, start[0], start[1]);

        return t[end_x][end_y] == INT_MAX ? -1 : t[end_x][end_y];
    }
};
