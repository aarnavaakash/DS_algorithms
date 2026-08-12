class Solution{
    public:

    int equilibriumPoint(long long a[], int n) {
        if(n == 1)
            return 1;
        else if(n == 2)
            return -1;

        long long cumu_sum[n];
        cumu_sum[0]  = a[0];
        long long totalSum = a[0];

        for(int i = 1; i<n; i++) {
            totalSum += a[i];

            cumu_sum[i] = cumu_sum[i-1] + a[i];
        }

        for(int i = 1; i<n; i++) {
            int left_sum  = cumu_sum[i] - a[i];
            int right_sum = totalSum-left_sum-a[i];

            if(left_sum == right_sum)
                return i+1;
        }

        return -1;
    }

};

class Solution{
    public:

    int equilibriumPoint(long long a[], int n) {
        if(n == 1)
            return 1;
        else if(n == 2)
            return -1;

        long long left_sum = a[0];
        long long totalSum = 0;

        for(int i = 0; i<n; i++) {
            totalSum += a[i];
        }

        for(int i = 1; i<n; i++) {
            int right_sum = totalSum-left_sum-a[i];

            if(left_sum == right_sum)
                return i+1;

            left_sum += a[i];
        }

        return -1;
    }

};
