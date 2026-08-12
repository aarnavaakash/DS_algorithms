class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int &x : arr) mp[x]++;

        auto lambda = [&](int &a, int &b){
            return abs(a) < abs(b);
        };

        sort(begin(arr), end(arr), lambda);

        for(int &x : arr) {
            if(mp[x] == 0) continue;

            if(mp.find(2*x) == end(mp) || mp[2*x] == 0) return false;

            mp[x]--;
            mp[2*x]--;
        }

        return true;
    }
};
