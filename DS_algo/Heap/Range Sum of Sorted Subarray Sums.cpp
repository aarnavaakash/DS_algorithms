class Solution {
public:
    int M = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        vector<int> temp;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                temp.push_back(sum);
            }
        }

        sort(begin(temp), end(temp));

        int result = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            result = (result + temp[i]) % M;
        }
        return result;
    }
};

class Solution {
public:
    typedef pair<int, int> P;
    int M = 1e9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int result = 0;

        for (int i = 1; i <= right; i++) {
            auto p = pq.top();
            pq.pop();

            if (i >= left) {
                result = (result + p.first) % M;
            }

            if (p.second < n - 1) {
                p.second++;
                p.first += nums[p.second];
                pq.push(p);
            }
        }
        return result;
    }
};
