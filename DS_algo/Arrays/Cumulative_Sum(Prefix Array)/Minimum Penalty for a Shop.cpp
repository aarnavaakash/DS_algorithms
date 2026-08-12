class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int minPenalty = INT_MAX;
        int minHour    = INT_MAX;

        for(int i = 0; i < n; i++) {

            int j = i-1;
            int penalty = 0;

            while(j >= 0) {
                if(customers[j] == 'N') {
                    penalty++;
                }
                j--;
            }

            j = i;

            while(j < n) {
                if(customers[j] == 'Y') {
                    penalty++;
                }
                j++;
            }

            if(penalty < minPenalty) {
                minPenalty = penalty;
                minHour    = i;
            }

        }

        int nthHourPenalty = count(customers.begin(), customers.end(), 'N');
        if(nthHourPenalty < minPenalty) {
                minPenalty = nthHourPenalty;
                minHour    = n;
        }

        return minHour;
    }
};

class Solution {
public:
    int bestClosingTime(string customers) {
        int n           = customers.length();

        vector<int> prefixN(n+1, 0);
        prefixN[0] = 0;

        vector<int> suffixY(n+1, 0);
        suffixY[n] = 0;

        for(int i = 1; i<=n; i++) {
            if(customers[i-1] == 'N') {
                prefixN[i] = prefixN[i-1] + 1;
            } else {
                prefixN[i] = prefixN[i-1];
            }
        }

        for(int i = n-1; i >= 0; i--) {
            if(customers[i] == 'Y') {
                suffixY[i] = suffixY[i+1]+1;
            } else {
                suffixY[i] = suffixY[i+1];
            }
        }

        int minPenalty = INT_MAX;
        int minHour    = INT_MAX;

        for(int i = 0; i<n+1; i++) {
            int currPenalty = prefixN[i] + suffixY[i];

            if(currPenalty < minPenalty) {
                minPenalty = currPenalty;
                minHour    = i;
            }
        }

        return minHour;
    }
};

class Solution {
public:
    int bestClosingTime(string customers) {
        int n           = customers.length();

        int minHour  = 0;
        int penalty  = count(begin(customers), end(customers), 'Y');

        int minPenalty = penalty;

        for(int i = 0; i< n ; i++) {

            if(customers[i] == 'Y') {
                penalty--;
            } else {
                penalty++;
            }

            if(penalty < minPenalty) {
                minHour = i+1;
                minPenalty = penalty;
            }
        }

        return minHour;

    }
};
