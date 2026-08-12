class Solution {
public:
    int solve_sliding_window(vector<int>& cardPoints, int& k) {

        int n        = nums.size();
        int totalSum = 0;
        int l        = n-k;
        int currSum  = 0;
        int minSum   = INT_MAX;
        int i = 0,  j = 0;

        while(j < n) {
            totalSum += nums[j];
            currSum  += nums[j];
            if(j-i+1 == l) {
                minSum   = min(minSum, currSum);
                currSum -= nums[i];
                i++;
            }
            j++;
        }
        return minSum == INT_MAX ? totalSum : totalSum-minSum;
    }

    int maxScore(vector<int>& cardPoints, int k) {
        return solve_sliding_window(cardPoints, k);
    }
};

class Solution {
public:
    int k, n;
    unordered_map<string, int> mp;
    int solve(vector<int>& nums, int i, int j, int count) {
        if(count == k)
            return 0;
        if(i >= n || j < 0)
            return 0;

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(count);
        if(mp.find(key) != end(mp))
            return mp[key];

        int take_i = nums[i] + solve(nums, i+1, j, count+1);
        int take_j = nums[j] + solve(nums, i, j-1, count+1);

        return mp[key] = max(take_i, take_j);
    }

    int maxScore(vector<int>& cardPoints, int k) {
        this->mp.clear();
        this->k = k;
        this->n = cardPoints.size();

        return solve(cardPoints, 0, n-1, 0);
    }
};

class Solution {
public:
    int solve_dp(vector<int>& cardPoints, int& k) {

        vector<int> front_card(k);
        vector<int> back_card(k);
        int n = cardPoints.size();
        front_card[0] = cardPoints[0];
        back_card[0]  = cardPoints[n-1];

        for(int i = 1; i<=k-1; i++) {
            front_card[i] = front_card[i-1] + cardPoints[i];
            back_card[i]  = back_card[i-1] + cardPoints[n-i-1];
        }

        int maxScr = max(back_card[k-1], front_card[k-1]);

        for(int i = 0; i<=k-2; i++) {

            int sum_front = front_card[i];
            int sum_back  = back_card[k-i-2];

            if(sum_front + sum_back > maxScr)
                maxScr = sum_front + sum_back;

        }

        return maxScr;

    }

    int maxScore(vector<int>& cardPoints, int k) {
        return solve_dp(cardPoints, k);
    }
};
