class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    if(nums[i] + nums[j] > nums[k] &&
                       nums[i] + nums[k] > nums[j] &&
                       nums[j] + nums[k] > nums[i]) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    int binarySearch(const vector<int>& nums, int l, int r, int target) {
        int k = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                k = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return k;
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
                continue;

            for (int j = i + 1; j < n; ++j) {

                int sum = nums[i] + nums[j];
                int k = binarySearch(nums, j + 1, n - 1, sum);
                if (k != -1)
                    count += (k - j);
            }
        }

        return count;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;

        sort(begin(nums), end(nums));
        int count = 0;

        for(int k = n-1; k > 1; k--) {
            int i = 0, j = k-1;

            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }

        return count;
    }
};
