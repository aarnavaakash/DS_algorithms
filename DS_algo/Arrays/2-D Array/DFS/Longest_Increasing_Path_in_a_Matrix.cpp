static const vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
    int m   = 0;
    int n   = 0;
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& store) {

        if(store[i][j] != 0)
            return store[i][j];

        int maxL = 1;

        for(vector<int> dir:directions) {
            int _i = i+dir[0];
            int _j = j+dir[1];

            if(_i < 0 || _j < 0 || _i >= m || _j >= n || matrix[i][j] >= matrix[_i][_j])
                continue;

            int len = 1 + solve(_i, _j, matrix, store);
            maxL = max(maxL, len);
        }

        return store[i][j] = maxL;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> store(m, vector<int>(n, 0));

        int result = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {

                int len = solve(i, j, matrix, store);

                result = max(result, len);
            }
        }

        return result;
    }
};
