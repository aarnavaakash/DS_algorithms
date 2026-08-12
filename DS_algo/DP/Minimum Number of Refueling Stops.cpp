typedef unsigned long long ull;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        vector<vector<ull>> t(n+1, vector<ull>(n+1, 0));

        for(int i = 0; i<n+1; i++) {
            t[i][0] = startFuel;
        }

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j <= i; j++) {

                t[i][j] = t[i-1][j];

                if(t[i-1][j-1] >= stations[i-1][0]) {
                    t[i][j] = max(t[i][j], t[i-1][j-1] + stations[i-1][1]);
                }

            }
        }

        for(int j = 0; j<n+1; j++) {
            if(t[n][j] >= target)
                return j;
        }

        return -1;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        vector<long long> t(n+1, 0);

        t[0] = startFuel;

        for(int i = 1; i<n+1; i++) {

            for(int j = i; j>=0; j--) {

                if(t[j] >= stations[i-1][0]) {

                    t[j+1] = max(t[j+1], t[j] + stations[i-1][1]);
                }
            }
        }

        for(int j = 0; j<n+1; j++) {
            if(t[j] >= target)
                return j;
        }

        return -1;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        priority_queue<int> pq;

        int curr = startFuel;
        int i = 0;
        int result = 0;
        while(curr < target) {
            while(i < n && curr >= stations[i][0]) {

                pq.push(stations[i][1]);

                i++;
            }

            if(pq.empty())
                return -1;

            int dist = pq.top();
            pq.pop();

            curr += dist;
            result++;
        }

        return result;

    }
};
