class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result(n-k+1, -1);

        int count = 1;

        for(int i = 1; i < k; i++) {
            if(nums[i] == nums[i-1]+1) {
                count++;
            } else {
                count = 1;
            }
        }

        if(count == k) {
            result[0] = nums[k-1];
        }

        int i = 1;
        int j = k;

        while(j < n) {
            if(nums[j] == nums[j-1]+1) {
                count++;
            } else {
                count = 1;
            }

            if(count >= k) {
                result[i] = nums[j];
            }

            i++;
            j++;
        }

        return result;

    }
};

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;
        vector<int> result;

        for(int j = 0; j < n; j++) {

            if(deq.size() == k) {
                deq.pop_front();
            }

            if(!deq.empty() && deq.back() != nums[j]-1) {
                deq.clear();
            }

            deq.push_back(nums[j]);

            if(j >= k-1) {
                if(deq.size() == k) {
                    result.push_back(deq.back());
                } else {
                    result.push_back(-1);
                }
            }
        }

        return result;
    }
};
