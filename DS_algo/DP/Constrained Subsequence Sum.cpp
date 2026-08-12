class Solution {
private:
    int n, k;
    unordered_map<string, int> mp;
public:
    int solve(vector<int>& nums, int last_chosen_index, int curr_index) {
        if(curr_index >= n)
            return 0;
        string key = to_string(last_chosen_index) + "_" + to_string(curr_index);

        if(mp.find(key) != end(mp))
            return mp[key];
        int result = 0;
        if(last_chosen_index == -1 || curr_index-last_chosen_index <= k) {

            int taken = nums[curr_index] + solve(nums, curr_index, curr_index+1);

            int not_taken = solve(nums, -1, curr_index+1);

            result = max(taken, not_taken);

	}
        return mp[key] = result;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        this->n = nums.size();
        this->k = k;

        int val = solve(nums, -1, 0);
        if(val == 0)
            return -1;
        return val;
    }
};

class Solution {
public:
    int t[100001];
    int K;

    int solve(int j, vector<int>& nums) {
        if (j < 0) {
            return 0;
        }

        if(t[j] != -1)
            return t[j];

        int max_val = 0;

        for (int i = 1; i <= K; ++i) {
            max_val = max(max_val, solve(j - i, nums));
        }

        return t[j] = nums[j] + max_val;
    }

    int constrainedSubsetSum(vector<int>& nums, int k) {
        memset(t, -1, sizeof(t));
        K = k;

        int result = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            result = max(result, solve(i, nums));
        }

        return result;
    }
};

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> t(n, 0);
        for(int i = 0; i<n; i++)
            t[i] = nums[i];

        int maxR = t[0];

        for(int i = 1; i<n; i++) {
            for(int j = i-1; i-j <= k && j >= 0; j--) {
                t[i] = max(t[i], nums[i] + t[j]);
            }

            maxR = max(maxR, t[i]);
        }

        return maxR;
    }
};

class Solution {
public:
    typedef pair<int, int> P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> t(n, 0);
        t = nums;
        priority_queue<P, vector<P>> pq;
        pq.push({t[0], 0});

        int maxR = t[0];

        for(int i = 1; i<n; i++) {

            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();

            t[i] = max(t[i], nums[i] + pq.top().first);
            pq.push({t[i], i});

            maxR = max(maxR, t[i]);
        }

        return maxR;
    }
};

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> t(nums);
        int maxR = t[0];

        for(int i = 0; i<n; i++) {

            while(!deq.empty() && deq.front() < i-k)
                deq.pop_front();

            if(!deq.empty())
                t[i] = max(t[i], nums[i] + t[deq.front()]);

            while(!deq.empty() && t[i] >= t[deq.back()])
                deq.pop_back();

            deq.push_back(i);

            maxR = max(maxR, t[i]);
        }

        return maxR;
    }
};
