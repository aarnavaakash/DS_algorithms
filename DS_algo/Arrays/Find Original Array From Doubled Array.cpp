class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        if(n%2 != 0) {
            return {};
        }

        sort(begin(changed), end(changed));

        map<int, int> mp;

        for(int &num : changed) {
            mp[num]++;
        }

        vector<int> result;

        for(int &num : changed) {
            int twice = 2*num;

            if(mp[num] == 0) continue;

            if(mp.find(twice) == mp.end() || mp[twice] == 0) {
                return {};
            }

            result.push_back(num);

            mp[num]--;
            mp[twice]--;
        }

        return result;
    }
};

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> result;

        sort(begin(changed), end(changed));

        for(int i = 0; i<n; i++) {
            int num = changed[i];
            if(num < 0) continue;

            auto idx = lower_bound(begin(changed)+i+1, end(changed), 2*num);

            if(idx != end(changed) && *idx == 2*num) {
                *idx = -1;
                result.push_back(num);
            } else {
                return {};
            }
        }

        return result;
    }
};
