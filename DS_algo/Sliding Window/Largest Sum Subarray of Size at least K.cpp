class Solution{
    public:
    long long int maxSumWithK(long long int arr[], long long int n, long long int k) {
        long long  sum     = 0;
        long long  result  = INT_MIN;
        long long  i       = 0;
        long long  trail   = 0;

        for (int j = 0; j < n; ++j) {
            sum += arr[j];

            if (j - i + 1 == k) {
                result = max(result, sum);
            } else if (j - i + 1 > k) {
                trail += arr[i];

                if (trail < 0) {
                    sum -= trail;
                    trail = 0;
                }

                result = max(result, sum);
                i++;
            }
        }

        return result;
    }
};

class Solution {
    public long maxSumWithK(long arr[], long n, long k) {
        long sum = 0;
        long result = Integer.MIN_VALUE;
        long i = 0;
        long trail = 0;

        for (int j = 0; j < n; ++j) {
            sum += arr[j];

            if (j - i + 1 == k) {
                result = Math.max(result, sum);
            } else if (j - i + 1 > k) {
                trail += arr[(int) i];

                if (trail < 0) {
                    sum -= trail;
                    trail = 0;
                }

                result = Math.max(result, sum);
                i++;
            }
        }

        return result;
    }
}
