class Solution {
public:
    vector<int> t;

    bool solve(int n) {

        if(n == 0) {
            return false;
        }

        if(t[n] != -1) {
            return t[n] == 1 ? true : false;
        }

        for(int k = 1; k*k <= n; k++) {

            if(solve(n - (k*k)) == false) {

                return t[n] = true;
            }

        }

        return t[n] = false;

    }

    bool winnerSquareGame(int n) {
        t.assign(n+1, -1);
        return solve(n);
    }
};

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> t(n+1, false);

        t[0] = false;

        for(int i = 1; i < n+1; i++) {

            for(int k = 1; k*k <= i; k++) {
                if(t[i - (k*k)] == false) {
                    t[i] = true;
                    break;
                }
            }
        }

        return t[n];
    }
};
