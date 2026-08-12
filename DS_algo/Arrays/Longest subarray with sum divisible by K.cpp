class Solution{
public:
	int longSubarrWthSumDivByK(int nums[], int n, int k) {
        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = -1;

        int result = 0;

        for(int i = 0; i<n; i++) {
            sum += nums[i];

            int rem = sum%k;

            if(rem < 0) {
                rem += k;
            }

            if(mp.find(rem) != mp.end()) {
                result = max(result, i - mp[rem]);
            } else {
                mp[rem] = i;
            }
        }

        return result;
	}
};
