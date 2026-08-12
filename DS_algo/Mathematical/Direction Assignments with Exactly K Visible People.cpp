class Solution {
public:
    long M = 1e9 + 7;

    long power(long a, long b) {
        if (b == 0) return 1;

        long half   = power(a, b / 2);
        long result = (half * half) % M;

        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;

        long num = 1;
        long den = 1;

        for (int i = 0; i < r; i++) {
            num = (num * (n - i)) % M;
            den = (den * (i + 1)) % M;
        }

        return (num * power(den, M - 2)) % M;
    }

    int countVisiblePeople(int n, int pos, int k) {
        long velnarqido = n;

        long ways = nCr(n - 1, k);
        return (int)((ways * 2) % M);
    }
};
