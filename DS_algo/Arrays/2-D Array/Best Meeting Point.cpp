class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> xCoord;
        vector<int> yCoord;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    xCoord.push_back(i);
                    yCoord.push_back(j);
                }
            }
        }

        sort(begin(xCoord), end(xCoord));
        sort(begin(yCoord), end(yCoord));

        int l = xCoord.size()/2;
        int x = xCoord[l];
        int y = yCoord[l];

        int d = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    d += abs(x-i) + abs(y-j);
                }
            }
        }

        return d;
    }
};

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> xCoord;
        vector<int> yCoord;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    xCoord.push_back(i);
                }
            }
        }

        for(int j = 0; j<n; j++) {
            for(int i = 0; i<m; i++) {
                if(grid[i][j] == 1) {
                    yCoord.push_back(j);
                }
            }
        }

        int l = xCoord.size()/2;
        int x = xCoord[l];
        int y = yCoord[l];

        int d = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    d += abs(x-i) + abs(y-j);
                }
            }
        }

        return d;
    }
};
