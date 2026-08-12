class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp = mat;
        int m = mat.size();
        int n = mat[0].size();
        k = k%n;
        if(k == 0) {
            return true;
        }

        for(int i = 0; i<m; i++) {
            if(i%2) {
                rotate(rbegin(mat[i]), rbegin(mat[i]) + k, rend(mat[i]));
            } else {
                rotate(begin(mat[i]), begin(mat[i]) + k, end(mat[i]));
            }
        }

        return temp == mat;
    }
};

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = (k%n);

        if(k == 0) {
            return true;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int currIdx = j;
                int finalIdx;

                if(i % 2 == 0) {
                    finalIdx = (j + k)%n;
                } else {
                    finalIdx = (j - k + n) % n;
                }

                if(mat[i][currIdx] != mat[i][finalIdx]) {
                    return false;
                }

            }
        }

        return true;
    }
};
