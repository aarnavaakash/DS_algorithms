class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> events;

        for(auto &trip : trips) {
            int count = trip[0];
            int start = trip[1];
            int end   = trip[2];

            events[start] += count;
            events[end] -= count;
        }

        int passCount = 0;

        for(auto &it : events) {
            passCount += it.second;

            if(passCount > capacity)
                return false;
        }

        return true;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {0};

        for(auto &trip : trips) {
            int count = trip[0];
            int start = trip[1];
            int end   = trip[2];

            diff[start] += count;
            diff[end]   -= count;
        }

        int cumSum = 0;

        for(int i = 0; i < 1001; i++) {
            cumSum += diff[i];

            if(cumSum > capacity)
                return false;
        }

        return true;
    }
};
