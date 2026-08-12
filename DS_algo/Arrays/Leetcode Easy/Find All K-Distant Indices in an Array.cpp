class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        vector<int> result;

        for(int j = 0; j < n; j++) {
            if(nums[j] == key) {
                int start = max(j-k, 0);
                int end   = min(j+k, n-1);

                if(result.size() > 0 && result.back() >= start) {
                    start = result.back()+1;
                }

                for(int i = start; i <= end; i++) {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};

import java.util.*;

class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        int n = nums.length;
        List<Integer> result = new ArrayList<>();

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int start = Math.max(j - k, 0);
                int end = Math.min(j + k, n - 1);

                if (!result.isEmpty() && result.get(result.size() - 1) >= start) {
                    start = result.get(result.size() - 1) + 1;
                }

                for (int i = start; i <= end; i++) {
                    result.add(i);
                }
            }
        }

        return result;
    }
}
