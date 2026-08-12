class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int N, M;

    int t[2001][2001][2];

    int solve(int i, int prevVal, bool increasing) {
        if(i == N) {
            return 1;
        }

        if(t[i][prevVal][increasing] != -1) {
            return t[i][prevVal][increasing];
        }

        int result = 0;
        if(increasing) {
            for(int nextVal = prevVal+1; nextVal <= M; nextVal++) {
                result = (result + solve(i+1, nextVal, false)) % MOD;
            }
        } else {
            for(int nextVal = 1; nextVal < prevVal; nextVal++) {
                result = (result + solve(i+1, nextVal, true)) % MOD;
            }
        }

        return t[i][prevVal][increasing] = result;
    }

    int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r-l+1;
        memset(t, -1, sizeof(t));

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {

            result = (result + solve(1, startVal, true)) % MOD;

            result = (result + solve(1, startVal, false)) % MOD;
        }

        return result;
    }
};

class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r-l+1;

        ll t[2001][2001][2];
        memset(t, 0, sizeof(t));

        for(int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 0; i--) {

            for(int prevVal = 1; prevVal <= M; prevVal++) {

                for(int nextVal = prevVal+1; nextVal <= M; nextVal++) {
                    t[i][prevVal][1] = (t[i][prevVal][1] + t[i+1][nextVal][0]) % MOD;
                }

                for(int nextVal = 1; nextVal < prevVal; nextVal++) {
                    t[i][prevVal][0] = (t[i][prevVal][0] + t[i+1][nextVal][1]) % MOD;
                }

            }
        }

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {

            result = (result + t[1][startVal][1]) % MOD;

            result = (result + t[1][startVal][0]) % MOD;
        }

        return result;

    }
};

class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r-l+1;

        ll t[2001][2001][2];

        for(int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 0; i--) {

            vector<ll> prefDir0(M+1, 0);
            vector<ll> prefDir1(M+1, 0);

            for(int prevVal = 1; prevVal <= M; prevVal++) {

                prefDir0[prevVal] = (prefDir0[prevVal-1] + t[i+1][prevVal][0]) % MOD;

                prefDir1[prevVal] = (prefDir1[prevVal-1] + t[i+1][prevVal][1]) % MOD;

            }

            for(int prevVal = 1; prevVal <= M; prevVal++) {

                t[i][prevVal][1] = (prefDir0[M] - prefDir0[prevVal] + MOD) % MOD;

                t[i][prevVal][0] = prefDir1[prevVal-1];

            }
        }

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {

            result = (result + t[1][startVal][1]) % MOD;

            result = (result + t[1][startVal][0]) % MOD;
        }

        return result;

    }
};
