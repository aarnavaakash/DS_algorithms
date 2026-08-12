class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        vector<int> diff(2051, 0);

        for (auto &log : logs) {
            int birth = log[0];
            int death = log[1];
            diff[birth] += 1;
            diff[death] -= 1;
        }

        int maxPop = 0;
        int currPop = 0;
        int result = 1950;

        for (int year = 1950; year <= 2050; year++) {
            currPop += diff[year];
            if (currPop > maxPop) {
                maxPop = currPop;
                result = year;
            }
        }

        return result;
    }
};

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> events;

        for (auto &log : logs) {
            events.push_back({log[0], +1});
            events.push_back({log[1], -1});
        }

        sort(events.begin(), events.end());

        int curr = 0, maxPop = 0, result = 0;

        for (auto &e : events) {
            curr += e.second;
            if (curr > maxPop) {
                maxPop = curr;
                result = e.first;
            }
        }

        return result;
    }
};
