class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> cumSum(n, 0);

        cumSum[0] = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i]%2 == nums[i-1]%2) {
                cumSum[i] = cumSum[i-1]+1;
            } else {
                cumSum[i] = cumSum[i-1];
            }
        }

        vector<bool> result(m, false);
        int i = 0;
        for(vector<int>& query : queries) {
            int start = query[0];
            int end = query[1];

            if(cumSum[end] - cumSum[start] == 0) {
                result[i] = true;
            }
            i++;
        }

        return result;
    }
};

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> validRightMostIdx(n);

        int i = 0;
        int j = 0;

        while(i < n) {
            if(j < i) {
                j = i;
            }

            while(j+1 < n && nums[j]%2 != nums[j+1]%2) {
                j++;
            }

            validRightMostIdx[i] = j;
            i++;
        }

        vector<bool> result(m, false);

        for(int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if(end <= validRightMostIdx[start]) {
                result[i] = true;
            }
        }

        return result;
    }
};

class Solution {
public:
    bool bSearch(vector<int>& vi, int sp, int ep) {
        int l = 0;
        int r = vi.size()-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(vi[mid] < sp) {
                l = mid+1;
            } else if(vi[mid] > ep) {
                r = mid-1;
            } else {

                return true;
            }
        }

        return false;

    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = nums.size();

        vector<int> vi;

        for(int i = 1; i < n; i++) {
            if(nums[i]%2 == nums[i-1]%2) {
                vi.push_back(i);
            }
        }

        vector<bool> result(m, false);

        for(int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            bool hasViolatingIndexInRange = bSearch(vi, start+1, end);

            if(hasViolatingIndexInRange == false) {
                result[i] = true;
            }
        }

        return result;

    }
};
