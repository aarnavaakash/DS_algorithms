class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if(n*n == mines.size())
            return 0;

        int t[n][n];
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                t[i][j] = 1;
            }
        }

        for(vector<int>& vec : mines)
            t[vec[0]][vec[1]] = 0;

        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(t[i][j] == 0) continue;

                int expand = 0;
                while(true) {
                    expand++;
                    if(i - expand < 0 || j - expand < 0 || i + expand >= n || j + expand >= n)
                        break;

                    if(t[i-expand][j] == 0 || t[i][j-expand] == 0 || t[i+expand][j] == 0 || t[i][j+expand] == 0)
                        break;
                }

                ans = max(ans, expand);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> t(n, vector<int>(n, 1));
        for(vector<int>& vec : mines) {
            t[vec[0]][vec[1]] = 0;
        }

        int ans = 0;
        vector<vector<int>> left, right, top, bottom;

        left = right = top = bottom = t;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i > 0 && top[i][j])   top[i][j] += top[i-1][j];
                if(j > 0 && left[i][j])  left[i][j]  += left[i][j-1];

                int x = n-i-1;
                int y = n-j-1;
                if(x < n-1 && bottom[x][y]) bottom[x][y] += bottom[x+1][y];
                if(y < n-1 && right[x][y])  right[x][y]   += right[x][y+1];
            }
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                int minL = min({left[i][j], right[i][j], top[i][j], bottom[i][j]});
                ans = max(ans, minL);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if(n*n == mines.size())
            return 0;

        int t[n][n];
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                t[i][j] = n;
            }
        }

        for(vector<int>& vec : mines)
            t[vec[0]][vec[1]] = 0;

        int ans = 0;

        for(int i = 0; i<n; i++) {

            int left = 0;
            for(int j = 0; j < n; j++) {
                left = t[i][j] == 0 ? 0 : left+1;
                t[i][j] = min(t[i][j], left);
            }

            int right = 0;
            for(int j = n-1; j>=0; j--) {
                right = t[i][j] == 0 ? 0 : right+1;
                t[i][j] = min(t[i][j], right);
            }

            int up = 0;
            for(int k = 0; k < n; k++) {
                up = t[k][i] == 0 ? 0 : up+1;
                t[k][i] = min(t[k][i], up);
            }

            int down = 0;
            for(int k = n-1; k >= 0; k--) {
                down = t[k][i] == 0 ? 0 : down+1;
                t[k][i] = min(t[k][i], down);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, t[i][j]);
            }
        }

        return ans;
    }
};
