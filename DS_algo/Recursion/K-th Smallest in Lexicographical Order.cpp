class Solution {
public:
    void solve(int curr, int n, vector<int>& result) {
        if(curr > n)
            return;

        result.push_back(curr);

        for(int nextDigit = 0; nextDigit <= 9; nextDigit++) {
            int nextnum = curr*10 + nextDigit;

            if(nextnum > n)
                return;

            solve(nextnum, n, result);
        }
    }

    int findKthNumber(int n, int k) {
        vector<int> result;

        for(int num = 1; num <= 9; num++)
            solve(num, n, result);

        return result[k-1];
    }
};

class Solution {
public:
    int count = 0;
    int result = 0;

    bool solve(long long curr, int n, int k) {
        if (curr > n)
            return false;

        count++;

        if (count == k) {
            result = curr;
            return true;
        }

        for (int nextDigit = 0; nextDigit <= 9; nextDigit++) {
            long long nextnum = curr * 10 + nextDigit;
            if (nextnum > n)
                break;

            if (solve(nextnum, n, k)) {
                return true;
            }
        }

        return false;
    }

    int findKthNumber(int n, int k) {
        for (long long num = 1; num <= 9; num++) {
            if (solve(num, n, k)) {
                break;
            }
        }

        return result;
    }
};

class Solution {
public:

    int Count(long curr, long next, int n) {
        int countNum = 0;

        while(curr <= n) {
            countNum += (next - curr);

            curr *= 10;
            next *= 10;

            next = min(next, long(n+1));
        }

        return countNum;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;

        while(k > 0) {
            int count = Count(curr, curr+1, n);
            if(count  <= k) {
                curr++;
                k -= count;
            } else {
                curr *= 10;
                k -= 1;
            }
        }

        return curr;

    }
};
