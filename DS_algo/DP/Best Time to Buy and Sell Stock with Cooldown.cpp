class Solution {
public:
    int t[5001][2];
    int maxP(vector<int>& prices, int day, int n, int buy) {
        if(day >= n)
            return 0;

        int profit = 0;
        if(t[day][buy] != -1) {
            return t[day][buy];
        }

        if(buy) {
            int consider      = maxP(prices, day+1, n, false) - prices[day];
            int not_consider  = maxP(prices, day+1, n, true);
            profit = max({profit, consider, not_consider});
        } else {
            int consider      = maxP(prices, day+2, n, true) + prices[day];
            int not_consider  = maxP(prices, day+1, n, false);
            profit = max({profit, consider, not_consider});
        }

        return t[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(t, -1, sizeof(t));
        return maxP(prices, 0, n, true);
    }
};

class Solution {
public:
    int maxP(vector<int>& prices, int& n) {
        if(n == 0 || n == 1)
            return 0;
        vector<int> t(n, 0);

        t[0] = 0;
        t[1] = max(prices[1] - prices[0], 0);

        for(int i = 2; i<n; i++) {
            t[i] = t[i-1];

            for(int j = 0; j<=i-1; j++) {

                int prev_profit = j>=2 ? t[j-2] : 0;

                t[i] = max(t[i], prices[i] - prices[j] + prev_profit);
            }
        }

        return t[n-1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxP(prices, n);
    }
};

Approach-3 (Optimizing Approach-1 to O(n))
class Solution {
public:
    int maxP(vector<int>& prices, int& n) {
        if(n == 0 || n == 1)
            return 0;

        vector<int> t(n, 0);
        int maxDiff = INT_MIN;

        for(int i = 0; i<n; i++) {
            if(i < 2)
                maxDiff = max(maxDiff, -prices[i]);
            if(i == 0)
                t[i] = 0;
            else if(i == 1)
                t[i] = max(prices[1] - prices[0], 0);
            else {

                t[i]    = max(t[i-1], prices[i] + maxDiff);
                maxDiff = max(maxDiff, t[i-2] - prices[i]);
            }
        }

        return t[n-1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxP(prices, n);
    }
};
