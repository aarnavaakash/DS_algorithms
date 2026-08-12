class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        int temp;
        while(start < end){
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);

    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());

        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
