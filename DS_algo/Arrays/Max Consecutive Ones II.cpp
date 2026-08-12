class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        vector<int> ones(n, 0);

        int count = 0;

        for(int i = 0; i<n; i++) {
            if(nums[i] == 0) {
                ones[i] = count;
                count = 0;
            } else {
                count++;
            }
        }

        count = 0;
        int result = 0;

        for(int i = n-1; i>=0; i--) {
            if(nums[i] == 0) {
                ones[i] += count;
                result = max(result, ones[i]+1);
                count = 0;
            } else {
                count++;
            }
        }

        return result;
    }
};

class Solution {
public:
    void moveUntilOneCount(vector<int>& nums, int& count, int& i, int& j) {
        if(count > 1) {
            while(j <= i && count > 1) {
                if(nums[j] == 0) {
                    count--;
                }
                j++;
            }
        }
    }
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        int result = 0;
        while(i < n) {
            if(nums[i] == 0) {
                count++;
                moveUntilOneCount(nums, count, i, j);
            }
            result = max(result, i-j+1);
            i++;
        }
        return result;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        int result = 0;
        while(i < n) {
            if(nums[i] == 0) {
                count++;
			}
			if(count > 1) {
				count -= nums[j] == 0 ? 1 : 0;
				j++;
			}
            result = max(result, i-j+1);
            i++;
        }
        return result;
    }
};
