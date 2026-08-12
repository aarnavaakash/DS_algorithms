class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int maxElem = ops.size();
        if(maxElem  == 0)
            return m*n;
        vector<vector<int>> t(m, vector<int>(n));
        int count = 0;
        for(vector<int> &vec : ops) {

            for(int i = 0; i<vec[0]; i++) {
                for(int j = 0; j<vec[1]; j++) {
                    t[i][j]++;
                    if(t[i][j] == maxElem)
                        count++;
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minX = m;
        int minY = n;

        for(vector<int> &vec : ops) {
            minX = min(minX, vec[0]);
            minY = min(minY, vec[1]);
        }

        return minX*minY;
    }
};
