class Solution {
public:
    int N;

    int solve(int i, int k, int currRate, vector<int>& position, vector<int>& time, vector<vector<vector<int>>>& t) {
        if(i == N-1) {
            if(k > 0) {
                return INT_MAX;
            }
            return 0;
        }

        if(t[i][k][currRate] != -1) {
            return t[i][k][currRate];
        }

        int result = INT_MAX;

        int skipResultTime = solve(i+1, k, time[i+1], position, time, t);
        if(skipResultTime != INT_MAX) {
            int dist           = position[i+1] - position[i];
            result             = min(result, dist*currRate + skipResultTime);
        }

        if(k > 0) {
            int mergeTime  = time[i+1];
            int mergeCount = 0;

            for(int j = i+2; j < N && mergeCount < k; j++) {
                mergeCount++;
                mergeTime += time[j];

                int mergeResultTime = solve(j, k - mergeCount, mergeTime, position, time, t);
                if(mergeResultTime != INT_MAX) {
                    int dist = position[j] - position[i];
                    result = min(result, dist*currRate + mergeResultTime);
                }
            }
        }

        return t[i][k][currRate] = result;
    }

    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        N = n;

        int cummulativeTime = 0;
        for(int &t : time) {
            cummulativeTime += t;
        }

        vector<vector<vector<int>>> t(n, vector<vector<int>>(k+1, vector<int>(cummulativeTime+1, -1)));

        return solve(0, k, time[0], position, time, t);
    }
};
