class Solution {
private:

public:
    bool possible(int weight, vector<int>& weights, int days) {
        int currDayCount  = 1;
        int currSumWeight = 0;
        for(int &w : weights) {
            currSumWeight += w;

            if(currSumWeight > weight) {
                currDayCount++;
                currSumWeight = w;
            }

        }

        return currDayCount<=days;

    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n     = weights.size();

        int minWeight = accumulate(begin(weights), end(weights), 0);
        int maxWt = *max_element(begin(weights), end(weights));

        if(n < days)
            return -1;

        if(days == 1)
            return minWeight;

        int high = minWeight;
        int low  = maxWt;

        while(low < high) {
            int mid = low + (high-low)/2;

            if(possible(mid, weights, days))
                high = mid;
            else
                low  = mid+1;
        }

        return high;
    }
};
