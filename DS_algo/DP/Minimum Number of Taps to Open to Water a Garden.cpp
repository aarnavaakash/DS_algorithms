class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min   = 0;
        int max   = 0;
        int count = 0;
        while(max < n) {

            for(int i = 0; i < n + 1; i++) {
                if(i-ranges[i] <= min && i+ranges[i] > max)
                    max = i+ranges[i];
            }

            if(max == min)
                return -1;

            min = max;
            count++;
        }

        return count;
    }
};

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1, 0);

        for(int i = 0; i<n+1; i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);

            jumps[l] = max(jumps[l], r-l);
        }

        int currEnd  = 0;
        int maxReach = 0;
        int count    = 0;
        for(int i = 0; i<n; i++) {
            maxReach = max(maxReach, jumps[i]+i);

            if(i == currEnd) {
                count++;
                currEnd = maxReach;
            }
        }

        if(currEnd >= n)
            return count;
        return -1;
    }
};

class Solution {
public:
    map<pair<int,int>,int> mp;
    int N;
    int solve(int i, int maxEnd, vector<pair<int,int>>& range) {
        if(i >= range.size())
            return maxEnd >= N ? 0 : 1e9;

        if(range[i].first > maxEnd)
            return 1e9;

        if(mp.find({i,maxEnd}) != mp.end())
            return mp[{i,maxEnd}];

        int not_open_tap = solve(i+1, maxEnd , range);

        int open_tap     = 1 + solve(i+1, max(maxEnd, range[i].second), range);

        return mp[{i, maxEnd}] = min(open_tap, not_open_tap);
    }

    int minTaps(int n, vector<int>& ranges) {
        N = n;

        vector<pair<int,int>> range;

        for(int i = 0; i < ranges.size(); i++) {

            int start = max(0, i - ranges[i]);
            int end   = min(n, i + ranges[i]);

            range.push_back({start, end});

        }

        sort(range.begin(), range.end());

        int ans = solve(0, 0, range);

        return ans == 1e9 ? -1 : ans;
    }
};

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> t(n+1, n+2);

        t[0] = 0;

        for(int i = 0; i<n+1; i++) {

            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);

            for(int j = l+1; j<=r; j++)

                t[j] = min(t[j], t[l]+1);

        }

        return t[n] > n+1 ? -1 : t[n];
    }
};
