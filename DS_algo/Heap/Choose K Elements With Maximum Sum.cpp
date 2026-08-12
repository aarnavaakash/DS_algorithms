class Solution {
public:
    typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();

        vector<ll> result(n, 0);

        for(int i = 0; i < n; i++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int j = 0; j < n; j++) {
                if(nums1[j] < nums1[i]) {

                    pq.push(nums2[j]);
                    if(pq.size() > k) {
                        pq.pop();
                    }
                }
            }

            long long sum = 0;
            while(!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }

            result[i] = sum;
        }

        return result;
    }
};

class Solution {
public:
    typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<vector<int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {nums1[i], i, nums2[i]};
        }

        sort(begin(vec), end(vec));

        vector<ll> result(n, 0);
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0;

        for(int i = 0; i < n; i++) {
            if(i > 0 && vec[i-1][0] == vec[i][0]) {
                ll ans = result[vec[i-1][1]];
                result[vec[i][1]] = ans;
            } else {
                result[vec[i][1]] = sum;
            }

            pq.push(vec[i][2]);
            sum += vec[i][2];
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        }

        return result;

    }
};
