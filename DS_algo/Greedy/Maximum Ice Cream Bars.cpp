class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));

        int count = 0;

        for(int &cost : costs) {
            if(cost > coins)
                return count;
            else {
                count++;
                coins -= cost;
            }
        }

        return count;
    }
};

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(begin(costs), end(costs));

        vector<int> count(maxCost + 1, 0);
        for (int cost : costs)
            count[cost]++;

        int total = 0;
        for (int cost = 1; cost <= maxCost; cost++) {
            if (count[cost] == 0)
                continue;

            if (coins < cost)
                break;

            int buy_kiya = min(count[cost], coins / cost);
            total += buy_kiya;
            coins -= buy_kiya * cost;
        }

        return total;
    }
};
