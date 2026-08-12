************************************************************ C++ ************************************************************

class Solution {
public:
    int n;
    int t[301][5001];

    int solve(int i, vector<int>& coins, int amount) {

        if(amount == 0)
            return t[i][amount] = 1;

        if(i == n || amount < 0)
            return 0;

         if(t[i][amount] != -1)
            return t[i][amount];

        if(coins[i] > amount)
            return t[i][amount] = solve(i+1, coins, amount);

        int take = solve(i, coins, amount-coins[i]);
        int skip = solve(i+1, coins, amount);

        return t[i][amount] = take+skip;

    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(0, coins, amount);
    }
};

class Solution {
public:
    int combi(vector<int>& coins, int amount, int n) {
        vector<vector<int>> t(n+1, vector<int>(amount+1));

        for(int i = 0; i<n+1; i++) {
            for(int j = 0; j<amount+1; j++) {
                if(j == 0) {
                    t[i][j] = 1;
                } else if(i == 0) {
                    t[i][j] = 0;
                } else if(coins[i-1] <= j) {
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        return combi(coins, amount, n);
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> ways(amount+1);

        ways[0] = 1;

        for(int i = 0; i<n; i++) {

            int curr_coin = coins[i];
            for(int j = curr_coin; j<=amount ; j++) {
                int remain_amount = j-curr_coin;

                ways[j] = ways[j] + ways[remain_amount];
            }
        }

        return ways[amount];
    }
};

************************************************************ JAVA ************************************************************

class Solution {
    int[][] memo;
    int n;

    public int numberOfWays(int[] coins, int i, int amount) {
        if (amount == 0) {
            return 1;
        }

        if (i == n || amount < 0) {
            return 0;
        }

        if (memo[i][amount] != -1) {
            return memo[i][amount];
        }

        if(coins[i] > amount) {
            return memo[i][amount] = numberOfWays(coins, i + 1, amount);
        }

        int take = numberOfWays(coins, i, amount - coins[i]);
        int skip = numberOfWays(coins, i + 1, amount);

        return memo[i][amount] = take+skip;
    }

    public int change(int amount, int[] coins) {
        n = coins.length;
        memo = new int[coins.length][amount + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        return numberOfWays(coins, 0, amount);
    }
}
