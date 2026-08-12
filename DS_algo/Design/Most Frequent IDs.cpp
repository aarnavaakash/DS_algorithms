class Solution {
public:
    typedef long long ll;

    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();

        unordered_map<ll, ll> mp;

        vector<ll> result(nums.size());

        priority_queue<pair<ll, ll>>pq;

        for(int i=0; i <n; i++){
            int ID = nums[i];
            int f  = freq[i];

            mp[ID] += f;

            pq.push({mp[ID], ID});

            while(pq.size() > 0 && mp[pq.top().second] != pq.top().first) {
                pq.pop();
            }

            result[i] = pq.top().first;
        }
        return result;
    }
};
