class Solution {
public:
    int t[31][5051];
    int minDiffSubset(vector<int>& stones, int n, int s1, int sum) {
        if(n == 0)
            return abs(sum-2*s1);

        if(t[n][s1] != -1)
            return t[n][s1];

        return t[n][s1] = min(minDiffSubset(stones, n-1, s1+stones[n-1], sum),
                              minDiffSubset(stones, n-1, s1, sum));
    }

    int lastStoneWeightII(vector<int>& stones) {
        memset(t, -1, sizeof(t));
        int sum = accumulate(begin(stones), end(stones), 0);
        int n   = stones.size();
        return minDiffSubset(stones, n, 0, sum);
    }
};

class Solution {
public:
    int minDiffSubset(vector<int>& stones, int n, int sum) {
        vector<vector<bool>> t(n+1, vector<bool>(sum/2+1));
        for(int col = 0; col<sum/2+1; col++)
            t[0][col] = false;
        for(int row = 0; row<n+1; row++)
            t[row][0] = true;

        for(int i = 1; i<n+1; i++) {
            for(int j = 1; j<sum/2+1; j++) {
                if(stones[i-1] <= j) {
                    t[i][j] = t[i-1][j-stones[i-1]] || t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        int i = sum/2;
        for(; i>=0; i--) {
            if(t[n][i] == true)
                break;
        }
        return (sum-2*i);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        int n = stones.size();
        return minDiffSubset(stones, n, sum);
    }
};
