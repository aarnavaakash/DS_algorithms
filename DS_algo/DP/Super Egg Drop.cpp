class Solution {
public:

    int t[101][10001];
    int solve(int e, int f) {
        if(e == 1 || f == 0 || f == 1)
            return f;

        int minAttempts = INT_MAX;
        if(t[e][f] != -1)
            return t[e][f];
        for(int i = 1; i<=f; i++) {
            int breaks = 0;
            int no_break = 0;
            if(t[e-1][i-1] != -1)
                breaks = t[e-1][i-1];
            else
                breaks = solve(e-1, i-1);

            if(t[e][f-i] != -1)
                no_break = t[e][f-i];
            else
                no_break = solve(e, f-i);

            int temp = 1 + max(breaks, no_break);

            minAttempts = min(minAttempts, temp);
        }

        return t[e][f] = minAttempts;
    }

    int solve_iter(int e, int f) {
        vector<vector<int>> t(e+1, vector<int>(f+1, 0));

        for(int row = 0; row<e+1; row++) {
            t[row][0] = 0;
        }

        for(int col = 0; col<f+1; col++) {
            t[0][col] = 0;
        }

        for(int col = 0; col<f+1; col++) {
            t[1][col] = col;
        }

        for(int row = 0; row<e+1; row++) {
            t[row][1] = 1;
        }

        for(int i = 2; i<e+1; i++) {
            for(int j = 2; j<f+1; j++) {
                t[i][j] = INT_MAX;

                for(int k = 1; k<=j; k++) {
                    int temp = 1 + max(t[i-1][k-1], t[i][j-k]);

                    if(temp < t[i][j])
                        t[i][j] = temp;
                }
            }
        }

        return t[e][f];
    }

    int binarySearch(int e, int f) {
        if(e == 1 || f == 0 || f == 1)
            return f;

        if(t[e][f] != -1)
            return t[e][f];

        int l = 0, h = f;
        int minAttempts = INT_MAX;
        while(l <= h) {
            int mid = l + (h-l)/2;

            int breaks   = binarySearch(e-1, mid-1);
            int no_break = binarySearch(e, f-mid);
            int temp     = 1 + max(breaks, no_break);
            minAttempts  = min(minAttempts, temp);

            if(left == right)
                break;

            if(breaks < no_break)
                l = mid+1;
            else
                h = mid-1;
        }

        return t[e][f] = minAttempts;
    }

    int binarySearchIterative(int e, int f) {
        vector<vector<int>> t(e+1, vector<int>(f+1));

        for(int row = 0; row<e+1; row++) {
            t[row][0] = 0;
        }

        for(int col = 0; col<f+1; col++) {
            t[0][col] = 0;
        }

        for(int col = 0; col<f+1; col++) {
            t[1][col] = col;
        }

        for(int row = 0; row<e+1; row++) {
            t[row][1] = 1;
        }

        for(int i = 2; i<e+1; i++) {
            for(int j = 2; j<f+1; j++) {
                int l = 0, h = j;
                t[i][j] = INT_MAX;
                while(l <= h) {
                    int mid = l + (h-l)/2;

                    int breaks   = t[i-1][mid-1];
                    int no_break = t[i][j-mid];
                    int temp     = 1 + max(breaks, no_break);

                    t[i][j]  = min(t[i][j], temp);

                    if(left == right)
                        break;

                    if(breaks < no_break)
                        l = mid+1;
                    else
                        h = mid-1;
                }
            }
        }
        return t[e][f];
    }

    int superEggDrop(int e, int f) {
        memset(t, -1, sizeof(t));

        return binarySearchIterative(e, f);
    }
};
