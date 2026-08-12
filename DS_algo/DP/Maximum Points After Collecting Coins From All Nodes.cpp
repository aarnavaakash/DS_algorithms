class Solution {
private:
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> t;

    int dfs(int i, int parent, int k, int power, const vector<int> &coins, unordered_map<int, vector<int>>& adj) {
        if (power >= 14)
          return 0;

        if (t.count(i) && t[i].count(parent) && t[i][parent].count(power)) {
            return t[i][parent][power];
        }

        int case1 = (coins[i] >> power) - k;
        int case2 = coins[i] >> (power + 1);

        for (int j : adj[i]) {
            if (j != parent) {
                case1 += dfs(j, i, k, power, coins, adj);
                case2 += dfs(j, i, k, power + 1, coins, adj);
            }
        }

        int result = max(case1, case2);
        t[i][parent][power] = result;
        return result;
    }

public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        unordered_map<int, vector<int>> adj(n);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, -1, k, 0, coins, adj);
    }
};

class Solution {
private:
    int t[100001][14];

    int dfs(int i, int parent, int k, int power, const vector<int> &coins, unordered_map<int, vector<int>>& adj) {
        if (power >= 14)
            return 0;

        if(t[i][power] != -1) {
            return t[i][power];
        }

        int case1 = (coins[i] >> power) - k;
        int case2 = coins[i] >> (power + 1);

        for (int j : adj[i]) {
            if (j != parent) {
                case1 += dfs(j, i, k, power, coins, adj);
                case2 += dfs(j, i, k, power + 1, coins, adj);
            }
        }

        int result = max(case1, case2);
        return t[i][power] = result;
    }

public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        memset(t, -1, sizeof(t));
        unordered_map<int, vector<int>> adj(n);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, -1, k, 0, coins, adj);
    }
};
