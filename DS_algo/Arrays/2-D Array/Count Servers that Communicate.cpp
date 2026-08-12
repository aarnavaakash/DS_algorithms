class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int resultServers = 0;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    bool canCommunicate = false;

                    for (int otherCol = 0; otherCol < n; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    if (canCommunicate) {
                        resultServers++;
                    } else {

                        for (int otherRow = 0; otherRow < m; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }

                        if (canCommunicate) {
                            resultServers++;
                        }
                    }
                }
            }
        }

        return resultServers;
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> indexColCount(n, 0);
        vector<int> indexRowCount(m, 0);

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) {
                    indexColCount[col] += 1;
                    indexRowCount[row] += 1;
                }
            }
        }

        int resultServers = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1 && (indexColCount[col] > 1 || indexRowCount[row] > 1)) {
                    resultServers++;
                }
            }
        }
        return resultServers;
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> colServerCount(n, 0);
        vector<int> RowAkelaServerCol(m, -1);

        int resultServers = 0;

        for(int row = 0; row < m; row++) {
            int countServersRow = 0;
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) {
                    countServersRow += 1;
                    colServerCount[col]++;
                    RowAkelaServerCol[row] = col;
                }
            }

            if(countServersRow > 1) {
                resultServers += countServersRow;
                RowAkelaServerCol[row] = -1;
            }
        }

        for(int row = 0; row < m; row++) {
            if(RowAkelaServerCol[row] != -1) {
                int col = RowAkelaServerCol[row];
                if(colServerCount[col] > 1) {
                    resultServers += 1;
                }
            }
        }

        return resultServers;

    }
};

class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int resultServers = 0;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    boolean canCommunicate = false;

                    for (int otherCol = 0; otherCol < n; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    if (canCommunicate) {
                        resultServers++;
                    } else {

                        for (int otherRow = 0; otherRow < m; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }

                        if (canCommunicate) {
                            resultServers++;
                        }
                    }
                }
            }
        }

        return resultServers;
    }
}

class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[] indexColCount = new int[n];
        int[] indexRowCount = new int[m];

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    indexColCount[col]++;
                    indexRowCount[row]++;
                }
            }
        }

        int resultServers = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1 && (indexColCount[col] > 1 || indexRowCount[row] > 1)) {
                    resultServers++;
                }
            }
        }
        return resultServers;
    }
}

class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[] colServerCount = new int[n];
        int[] rowAkelaServerCol = new int[m];
        Arrays.fill(rowAkelaServerCol, -1);

        int resultServers = 0;

        for (int row = 0; row < m; row++) {
            int countServersRow = 0;
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    countServersRow++;
                    colServerCount[col]++;
                    rowAkelaServerCol[row] = col;
                }
            }

            if (countServersRow > 1) {
                resultServers += countServersRow;
                rowAkelaServerCol[row] = -1;
            }
        }

        for (int row = 0; row < m; row++) {
            if (rowAkelaServerCol[row] != -1) {
                int col = rowAkelaServerCol[row];
                if (colServerCount[col] > 1) {
                    resultServers++;
                }
            }
        }

        return resultServers;
    }
}
