class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maj = NULL;

        for(int i = 0; i<n; i++) {
            if(count == 0) {
                count = 1;
                maj = nums[i];
            }
            else if(nums[i] == maj) {
                count++;
            } else {
                count--;
            }
        }

        return maj;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maj = NULL;

        for(int i = 0; i<n; i++) {
            if(nums[i] == maj) {
                count++;
            } else if(count == 0) {
                maj = nums[i];
                count = 1;
            } else {
                count--;
            }

        }

        return maj;
    }
};
