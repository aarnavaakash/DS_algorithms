class Solution {
public:
    int n;
    int t[501];
    int solve(vector<int>& arr, int idx, int k) {
        if(idx >= n) {
            return 0;
        }

        if(t[idx] != -1) {
            return t[idx];
        }

        int result = 0;
        int curr_max = -1;
        for(int i = idx; i < n && i-idx+1 <= k; i++) {
            curr_max = max(curr_max, arr[i]);

            result = max(result, curr_max*(i-idx+1) + solve(arr, i+1, k));
        }

        return t[idx] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr, 0, k);
    }
};

class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] t = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            int currMax = -1;

            for (int j = 1; j <= k && i - j >= 0; j++) {
                currMax = Math.max(currMax, arr[i - j]);
                t[i] = Math.max(t[i], t[i - j] + currMax * j);
            }
        }

        return t[n];
    }
}
