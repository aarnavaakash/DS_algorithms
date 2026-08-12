class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1000000));

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int left = dist[i][max(0, j-1)];
                    int top  = dist[max(0, i-1)][j];

                    dist[i][j] = min(dist[i][j], 1 + min(left, top));
                }
            }
        }

        for(int i = m-1; i>=0; i--) {
            for(int j = n-1; j>=0; j--) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int right = dist[i][min(n-1, j+1)];
                    int down  = dist[min(m-1, i+1)][j];

                    dist[i][j] = min(dist[i][j], 1 + min(right, down));
                }
            }
        }

        return dist;
    }
};
