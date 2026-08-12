************************************************************ C++ ************************************************************

class Solution {
public:
    int m, n;
    typedef pair<int, int> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        queue<P> que;
        vector<vector<int>> dist(m, vector<int>(n, -1));

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        auto isSafe = [](int& i, int& j, int& m, int& n) {
            return i>=0 && i<m && j>=0 && j<n;
        };

        while(!que.empty()) {
            P p = que.front();
            que.pop();

            for(auto &dir : directions) {
                int i = p.first  + dir[0];
                int j = p.second + dir[1];

                if(isSafe(i, j, m, n)) {
                    if(dist[i][j] == -1) {
                        que.push({i, j});
                        dist[i][j] = 1 + dist[p.first][p.second];
                    }
                }
            }

        }

        return dist;

    }
};

************************************************************ JAVA ************************************************************

public class Solution {
    int m, n;
    int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int[][] updateMatrix(int[][] matrix) {
        m = matrix.length;
        n = matrix[0].length;

        int[][] result = new int[m][n];

        Queue<int[]> que = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    result[i][j] = 0;
                    que.offer(new int[] {i, j});
                }
                else {
                    result[i][j] = -1;
                }
            }
        }

        while (!que.isEmpty()) {
            int[] cell = que.poll();
            int i = cell[0];
            int j = cell[1];

            for (int[] dir : directions) {

                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && result[new_i][new_j] == -1) {
                    result[new_i][new_j] = result[i][j] + 1;
                    que.add(new int[] {new_i, new_j});
                }
            }
        }

        return result;
    }
}
