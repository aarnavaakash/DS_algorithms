class Solution {
public:

    bool binarySearch(vector<int>& arr, int need) {
        int low = 0, hi = arr.size() - 1;

        while(low <= hi) {
            int mid = low + (hi - low) / 2;
            if(arr[mid] == need)
                return true;
            else if(arr[mid] < need)
                low = mid + 1;
            else
                hi = mid - 1;
        }

        return false;
    }

    bool splitArraySameAverage(vector<int>& nums) {
        int N = nums.size();
        int S = accumulate(begin(nums), end(nums), 0);
        int n1 = N/2;
        int n2 = N - n1;

        unordered_map<int, vector<int>> sumsLeft;
        for(int mask = 0; mask < (1 << n1); mask++) {
            int s = 0;
            int count = 0;
            for(int i = 0; i < n1; i++) {
                if(mask & (1 << i)) {
                    s += nums[i];
                    count++;
                }
            }
            sumsLeft[count].push_back(s);
        }

        unordered_map<int, vector<int>> sumsRight;
        for(int mask = 0; mask < (1 << n2); mask++) {
            int s = 0;
            int count = 0;
            for(int i = 0; i < n2; i++) {
                if(mask & (1 << i)) {
                    s += nums[n1+i];
                    count++;
                }
            }
            sumsRight[count].push_back(s);
        }

        for(int count = 0; count <= n2; count++) {

            sort(begin(sumsRight[count]), end(sumsRight[count]));
        }

        for(int k = 0; k <= n1; k++) {
            for(int leftSubSum : sumsLeft[k]) {

                for(int m = 0; m <= n2; m++) {
                    int size = k + m;
                    if(size == 0 || size == N) continue;

                    if(size * S % N != 0)
                        continue;

                    int need = size * S / N - leftSubSum;

                    if(binarySearch(sumsRight[m], need)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
