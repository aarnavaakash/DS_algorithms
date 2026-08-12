class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        int maxE = nums[0];

        for(int i = 0; i<n; i++) {
            maxE = max(maxE, nums[i]);
            int j = i+1;
            for(; j<n; j++) {
                if(nums[j] < maxE)
                    break;
            }
            if(j == n)
                return i+1;
        }

        return -1;
    }
};

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        vector<int> minRight(n);
        minRight[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            minRight[i] = min(minRight[i+1], nums[i]);
        }

        int maxLeft = nums[0];
        for(int i = 0; i<n-1; i++) {
            maxLeft = max(maxLeft, nums[i]);

            if(maxLeft <= minRight[i+1])
                return i+1;
        }
        return -1;
    }
};

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        int leftMax  = nums[0];
        int currMax  = nums[0];
        int len      = 1;

        for(int i = 1; i<n; i++) {
            if(nums[i] < leftMax) {

                len = i+1;

                leftMax = currMax;

            } else {
                currMax = max(currMax, nums[i]);
            }
        }

        return len;
    }
};
