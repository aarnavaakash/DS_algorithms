class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();

        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            int profit_1 = v1[1] - v1[0];
            int profit_2 = v2[1] - v2[0];

            return profit_1>profit_2;
        };

        sort(begin(costs), end(costs), lambda);

        int cost = 0;
        for(int i = 0; i<n/2; i++) {
            cost += costs[i][0];
        }

        for(int i = n/2; i<n; i++) {
            cost += costs[i][1];
        }

        return cost;
    }
};

class Solution {
public:
    int t[51][51];
    int solve_recurMemo(vector<vector<int>>& costs, int A, int B, int n) {
        if(A+B >= n)
            return 0;

        if(t[A][B] != -1)
            return t[A][B];

        int min_cost = INT_MAX;

        if(A < n/2) {
            min_cost = solve_recurMemo(costs, A+1, B, n) + costs[A+B][0];
        }
        if(B < n/2) {
            min_cost = min(min_cost, solve_recurMemo(costs, A, B+1, n) + costs[A+B][1]);
        }

        return t[A][B] = min_cost;

    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost = 0;
        int n = costs.size();
        int A = 0;
        int B = 0;
        memset(t, -1, sizeof(t));
        return solve_recurMemo(costs, 0, 0, n);
    }
};

class Solution {
public:
    int solve_BottomUp(vector<vector<int>>& costs, int &n) {
        int half = n/2;
        vector<vector<int>> t(half+1, vector<int>(half+1));

        t[0][0] = 0;

        for (int i = 1; i <= half; i++)
            t[i][0] = t[i - 1][0] + costs[i - 1][0];

        for (int j = 1; j <= half; j++)
            t[0][j] = t[0][j - 1] + costs[j - 1][1];

        for(int i = 1; i<half+1; i++) {
            for(int j = 1; j<half+1; j++) {
                int choose_A = costs[i+j-1][0] + t[i-1][j];
                int choose_B = costs[i+j-1][1] + t[i][j-1];
                t[i][j] = min(choose_A, choose_B);
            }
        }

        return t[half][half];
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        return solve_BottomUp(costs, n);
    }
};
