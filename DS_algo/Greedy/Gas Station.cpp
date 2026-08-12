class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i = 0; i<n; i++) {

            if(gas[i] < cost[i])
                continue;

            int j = (i+1)%n;

            int currGas = gas[i];

            currGas = currGas - cost[i] + gas[j];

            while(j != i) {
                if(currGas < cost[j])
                    break;

                int costForMovingFromThisj = cost[j];

                j = (j+1)%n;

                int gasEarnInNextStationj = gas[j];

                currGas = currGas - costForMovingFromThisj + gasEarnInNextStationj;

            }

            if(i == j)
                return i;
        }

        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int sumGas = accumulate(begin(gas), end(gas), 0);

        int sumCost = accumulate(begin(cost), end(cost), 0);

        if(sumGas < sumCost)
            return -1;

        int total  = 0;
        int result = 0;

        for(int i = 0; i<n; i++) {

            total += gas[i] - cost[i];

            if(total < 0) {
                total = 0;
                result = i+1;
            }

        }
        return result;
    }
};
