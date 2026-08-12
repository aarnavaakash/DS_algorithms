class Solution {
public:
    int n;

    int t[101][101][101];
    int solve(vector<int>& nums, int k, int i, int op1, int op2) {

        if(i == n) {
            return 0;
        }
        if(t[i][op1][op2] != -1) {
            return t[i][op1][op2];
        }
        int result = INT_MAX;

        if(op1 > 0) {
            int newVal = (nums[i]+1)/2;
            int applyOp1 = newVal + solve(nums, k, i+1, op1-1, op2);
            result = min(result, applyOp1);
        }

        if(op2 > 0 && nums[i] >= k) {
            int newVal = nums[i] - k;
            int applyOp2 = newVal + solve(nums, k, i+1, op1, op2-1);
            result = min(result, applyOp2);
        }

        if(op1 > 0 && op2 > 0) {
            int newVal = (nums[i]+1)/2;

            if(newVal >= k) {
                newVal = newVal-k;
                int applyOp1Op2 = newVal + solve(nums, k, i+1, op1-1, op2-1);
                result = min(result, applyOp1Op2);
            }

            if(nums[i] >= k) {
                newVal = nums[i] - k;

                newVal = (newVal + 1)/2;

                int applyOp2Op1 = newVal + solve(nums, k, i+1, op1-1, op2-1);
                result = min(result, applyOp2Op1);
            }
        }

        result = min(result, nums[i] + solve(nums, k, i+1, op1, op2));

        return t[i][op1][op2] = result;

    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, k, 0, op1, op2);
    }
};
