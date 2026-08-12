class Solution {
public:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int end_x, end_y;
    bool visited[101][101];

    bool DFS(vector<vector<int>> &maze, int x, int y) {
        if(x == end_x && y == end_y) {
            return true;
        }

        if(visited[x][y])
            return false;

        visited[x][y] = true;
        for(pair<int, int>& p : directions) {
             int x_ = x + p.first;
             int y_ = y + p.second;

             while (x_ >= 0 && x_ < maze.size() && y_ >= 0 && y_ < maze[0].size() && maze[x_][y_] == 0) {
                     x_ += p.first;
                     y_ += p.second;
             }

             x_ -= p.first;
             y_ -= p.second;
             if(!visited[x_][y_] && DFS(maze, x_, y_)) {
                 return true;
             }
        }
        return false;
    }

    bool BFS(vector<vector<int>> &maze, int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});
        visited[x][y] = true;
        while(!que.empty()) {
            pair<int, int> curr = que.front();
            que.pop();

            if(curr.first == end_x && curr.second == end_y)
                return true;

            for(pair<int, int>& p : directions) {
                int x_ = curr.first + p.first;
                int y_ = curr.second + p.second;

                while (x_ >= 0 && x_ < maze.size() && y_ >= 0 && y_ < maze[0].size() && maze[x_][y_] == 0) {
                    x_ += p.first;
                    y_ += p.second;
                }

                x_ -= p.first;
                y_ -= p.second;

                if(!visited[x_][y_]) {
                    que.push({x_, y_});
                    visited[x_][y_] = true;
                }
            }
        }

        return false;
    }

    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int x     = start[0];
        int y     = start[1];
        memset(visited, 0, sizeof(visited));
        end_x = destination[0];
        end_y = destination[1];

        return DFS(maze, x, y);
    }
};
