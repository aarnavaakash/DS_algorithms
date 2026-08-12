int MOD = 1e9+7;
class Solution {
public:

    int findPower(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half = findPower(a, b/2);
        long long result = (half * half) % MOD;

        if(b%2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    long long nCr(int n, int r, vector<long long>& factorial, vector<long long>& fermatFact) {

        return factorial[n] * fermatFact[n-r] % MOD * fermatFact[r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n+1, 1);
        factorial[0] = 1;
        factorial[1] = 1;
        for(int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i-1] * i) % MOD;
        }

        vector<long long> fermatFact(n+1, 1);
        for(int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(factorial[i], MOD-2);
        }

        long long result = nCr(n-1, k, factorial, fermatFact);

        result = result * m % MOD;

        result = result * findPower(m-1, n-k-1) % MOD;

        return result;
    }
};

class Solution {
public:
    int MOD = 1e9+7;

    int findPower(long long a, long long b) {
        long long result = 1;
        a %= MOD;

        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }

        return result;
    }

    long long nCr(int n, int r, vector<long long>& factorial) {
        long long numerator = factorial[n];
        long long denom1 = findPower(factorial[n - r], MOD - 2);
        long long denom2 = findPower(factorial[r], MOD - 2);

        long long result = (((numerator * denom1) % MOD) * denom2) % MOD;
        return result;
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        long long result = nCr(n - 1, k, factorial);
        result = result * m % MOD;
        result = result * findPower(m - 1, n - k - 1) % MOD;

        return result;
    }
};
