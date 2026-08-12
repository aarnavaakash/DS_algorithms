class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m*n != r*c)
            return mat;

        vector<vector<int>> newMat(r, vector<int>(c));

        int i = 0, j = 0;
        int k = 0, l = 0;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(l >= c) {
                    k++;
                    l = 0;
                }
                newMat[k][l] = mat[i][j];
                l++;
            }
        }
        return newMat;
    }
};

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m*n != r*c)
            return mat;

        vector<vector<int>> newMat(r, vector<int>(c));

        for(int i = 0; i<m*n; i++) {
            newMat[i/c][i%c] = mat[i/n][i%n];
        }

        return newMat;
    }
};
