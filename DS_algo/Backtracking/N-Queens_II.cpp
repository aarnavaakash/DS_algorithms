class Solution {
public:
    int count = 0;
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antiDiags;
    void dfs(int row, int n) {
        if(row == n) {
            count++;
            return;
        }

        for(int col = 0; col<n; col++) {
            int d  = row-col;
            int ad = row+col;

            if(cols.count(col) || diags.count(d) || antiDiags.count(ad))
                continue;

            cols.insert(col);
            diags.insert(d);
            antiDiags.insert(ad);

            dfs(row+1, n);

            cols.erase(col);
            diags.erase(d);
            antiDiags.erase(ad);

        }
    }
    vector<vector<string>> result;
    int totalNQueens(int n) {
        count = 0;
        if(n == 1)
            return 1;
        if(n <= 3)
            return count;

        dfs(0, n);

        return count;

    }
};
