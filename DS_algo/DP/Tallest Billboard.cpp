class Solution {
public:
    int n;

    int solve(vector<int>& rods, int i, int s1, int s2) {

        if (i == n) {
            if (s1 == s2)
                return s1;

            return 0;
        }

        int ans = 0;

        int nothing  = solve(rods, i + 1 , s1 , s2);
        int in_rod_1 = solve(rods, i + 1 , s1 + rods[i], s2);
        int in_rod_2 = solve(rods, i + 1 , s1 , s2 + rods[i]);

        return max({nothing, in_rod_1, in_rod_2});
    }

    int tallestBillboard(vector<int>& rods) {
        n = rods.size();

        return solve(rods, 0, 0, 0);
    }
};

class Solution {
public:
    int n;
    int t[21][10003];
    int solve(vector<int>& rods, int i, int diff) {

        if (i == n) {
            if (diff == 0)
                return 0;

            return INT_MIN;
        }

        if( t[i][diff+5000] != -1)
            return  t[i][diff+5000];

        int ans = 0;

        int nothing     = solve(rods, i + 1 , diff);
        int in_rod_1    = rods[i] + solve(rods, i + 1 , diff + rods[i]);
        int not_in_rod1 = rods[i] + solve(rods, i + 1 , diff - rods[i]);

        return t[i][diff+5000] = max({nothing, in_rod_1, not_in_rod1});
    }

    int tallestBillboard(vector<int>& rods) {
        n = rods.size();

        memset(t, -1, sizeof(t));

        return solve(rods, 0, 0)/2;
    }
};
