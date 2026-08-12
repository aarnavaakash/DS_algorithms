class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int i, int k) {

        if(k <= 0 || i >= n)
            return 0;

        int start = events[i][0];
        int end   = events[i][1];
        int value = events[i][2];

        if(t[i][k] != -1)
            return t[i][k];

        int j = i+1;
        for(; j < n; j++) {
            if(events[j][0] > events[i][1])
                break;
        }

        int take = value + solve(events, j, k-1);
        int skip = solve(events, i+1, k);

        return t[i][k] = max(take, skip);

    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));

        n = events.size();

        t.resize(n+1, vector<int>(k+1, -1));

        return solve(events, 0, k);
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int i, int k) {

        if(k <= 0 || i >= n)
            return 0;

        int start = events[i][0];
        int endt   = events[i][1];
        int value = events[i][2];

        if(t[i][k] != -1)
            return t[i][k];

        vector<int> temp = {endt, INT_MAX, INT_MAX};
        int j = upper_bound(events.begin(), events.end(), temp) - events.begin();

        int take = value + solve(events, j, k-1);
        int skip = solve(events, i+1, k);

        return t[i][k] = max(take, skip);

    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));

        n = events.size();

        t.resize(n+1, vector<int>(k+1, -1));

        return solve(events, 0, k);
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int i, int prev, int k) {

        if(k == 0 || i == n)
            return 0;

        if(t[prev+1][k] != -1)
            return t[prev+1][k];

        int start = events[i][0];
        int endt   = events[i][1];
        int value = events[i][2];

        int take = 0, skip = 0;
        if(prev == -1 || events[prev][1] < events[i][0]) {
            take = value + solve(events, i+1, i, k-1);
        }

        skip = solve(events, i+1, prev, k);

        return t[prev+1][k] = max(take, skip);

    }

    int maxValue(vector<vector<int>>& events, int k) {

        auto lambda = [&](auto &a, auto &b) {
            if(a[1]==b[1])
                return a[0]-b[0];

            return a[1]-b[1];
        };

        sort(begin(events), end(events));

        n = events.size();

        t.resize(n+1, vector<int>(k+1, -1));

        return solve(events, 0, -1, k);
    }
};
