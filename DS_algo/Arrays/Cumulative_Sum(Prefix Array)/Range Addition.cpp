class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> nums(length);

        for(vector<int> &vec : updates) {
            int start  = vec[0];
            int end    = vec[1];
            int update = vec[2];

            for(int i = start; i<= end; i++) {
                nums[i] += update;
            }
        }

        return nums;
    }
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> nums(length);

        for(vector<int> &vec : updates) {
            int start    = vec[0];
            int end_next = vec[1]+1;
            int update   = vec[2];

            nums[start] += update;
            if(end_next < length)
                nums[end_next] -= update;

        }

        for(int i = 1; i<length; i++)
            nums[i] += nums[i-1];

        return nums;
    }
};
