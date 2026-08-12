class Solution {
public:
    typedef pair<int, int> p;

    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<p, vector<p>, greater<p>> pq;

        unordered_map<int, int> mp;
        for(int i : nums)
            mp[i]++;

        for(auto it:mp) {
            pq.push({it.second, it.first});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int &num : nums) {
            mp[num]++;
        }

        vector<vector<int>> bucket(n+1);

        for(auto &it : mp) {
            int element = it.first;
            int freq    = it.second;

            bucket[freq].push_back(element);
        }

        vector<int> result;
        for(int i = n; i >= 0; i--) {

            if(bucket[i].size() == 0) continue;

            int size = bucket.size();
            while(bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }

        }

        return result;
    }
};
