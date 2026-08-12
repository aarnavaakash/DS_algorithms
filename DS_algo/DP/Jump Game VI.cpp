class Solution {
public:
    int maxScore = INT_MIN;
    int K;
    int n;
    unordered_map<int, int> mp;

    int maxScoreUtilRecursionMemo(vector<int>& nums, int idx) {
        if(idx == n-1) {
            return nums[idx];
        }
        if(mp.find(idx) != mp.end())
            return mp[idx];

        int maxScore = INT_MIN;
        for(int i = idx+1; i<=min(idx+K, n-1); i++) {
            maxScore = max(maxScore, maxScoreUtilRecursionMemo(nums, i));
        }

        return mp[idx] = nums[idx] + maxScore;
    }

	int maxResult(vector<int>& nums, int k) {
		n = nums.size();
		K = k;
		return maxScoreUtilRecursionMemo(nums, 0);
    	}
};

class Solution {
public:
    int maxScore = INT_MIN;
    int K;
    int n;

    int maxScoreUtilBottomUp(vector<int>& nums) {
        vector<int> t(n, -1);

        t[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            int maxNextStep = INT_MIN;
            for(int j = 1; j<=K; j++) {
                maxNextStep = max(maxNextStep, t[min(i+j, n-1)]);
            }

            t[i] = nums[i] + maxNextStep;
        }
        return t[0];
    }

	int maxResult(vector<int>& nums, int k) {
        n = nums.size();
        K = k;

        return maxScoreUtilBottomUp(nums);
    }

class Solution {
public:
    int maxScore = INT_MIN;
    int K;
    int n;

    int maxScoreUtilOptimized(vector<int>& nums) {
        vector<int> t(n, -1);

        t[n-1] = nums[n-1];

        deque<int> deq;

        deq.push_back(n-1);

        for(int i = n-2; i>=0; i--) {

            while(!deq.empty() && deq.front() > i+K)
                deq.pop_front();

            t[i] = nums[i] + t[deq.front()];

            while(!deq.empty() && t[deq.back()] <= t[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
        }
        return t[0];
    }

    int maxResult(vector<int>& nums, int k) {
        n = nums.size();
        K = k;

        return maxScoreUtilOptimized(nums);
    }
};

typedef pair<int, int> P;
class Solution {
public:
    struct comparator{
        bool operator()(P& p1, P& p2) {
            return p1.first < p2.first;
        }
    };
    int maxResult(vector<int>& nums, int k) {
        priority_queue<P, vector<P>, comparator> pq;

        int n = nums.size();
        pq.push({nums[0], 0});
        for(int i = 1; i<n; i++) {

            while(i - k > pq.top().second) {
                pq.pop();
            }

            pq.push({nums[i] + pq.top().first, i});
        }

        while(!pq.empty() && pq.top().second != n-1)
            pq.pop();

        return pq.top().first;
    }
};
