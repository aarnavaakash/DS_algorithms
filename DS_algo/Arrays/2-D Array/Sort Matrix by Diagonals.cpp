class Solution {
public:
    int n;

    void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool asc) {
        vector<int> vec;

        int i = r;
        int j = c;

        while(i < n && j < n) {
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(asc) {
            sort(begin(vec), end(vec));
        } else {
            sort(rbegin(vec), rend(vec));
        }

        i = r;
        j = c;
        for(int &val : vec) {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        for(int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false);
        }

        for(int col = 1; col < n; col++) {
            sortDiagonal(0, col, grid, true);
        }

        return grid;
    }
};

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i-j;
                mp[diag].push_back(grid[i][j]);
            }
        }

        for(auto &it : mp) {
            if(it.first >= 0) {
                sort(begin(it.second), end(it.second));
            } else {
                sort(rbegin(it.second), rend(it.second));
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i-j;
                grid[i][j] = mp[diag].back();
                mp[diag].pop_back();
            }
        }

        return grid;
    }
};
