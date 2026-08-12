class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();

        int result = 0;

        for(int i = 0; i < n; i++) {

            int count0 = 0;
            int count1 = 0;

            for(int j = i; j < n; j++) {
                if(s[j] == '0') {
                    count0++;
                } else {
                    count1++;
                }

                if(count0 <= k || count1 <= k) {
                    result += 1;
                } else {
                    break;
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();

        int result = 0;

        int count0 = 0;
        int count1 = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            if(s[j] == '0') {
                count0++;
            } else {
                count1++;
            }

            while(count0 > k && count1 > k) {
                if(s[i] == '0') {
                    count0--;
                } else {
                    count1--;
                }
                i++;
            }

            result += (j - i + 1);
            j++;
        }

        return result;
    }
};

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> leftMost(n, 0);
        vector<int> rightMost(n, 0);

        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;

        while(j < n) {
            mp[s[j]]++;
            while(mp['0'] > k && mp['1'] > k) {
                mp[s[i]]--;
                i++;
            }

            leftMost[j] = i;
            j++;
        }

        mp.clear();
        i = n-1;
        j = n-1;
        while( j >= 0) {
            mp[s[j]]++;
            while(mp['0'] > k && mp['1'] > k) {
                mp[s[i]]--;
                i--;
            }
            rightMost[j] = i;
            j--;
        }

        vector<int> tempValidSubstr(n, 0);
        for(int j = 0; j < n; j++) {
            tempValidSubstr[j] = j - leftMost[j] + 1;
        }

        vector<long long> cumSum(n, 0);
        cumSum[0] = tempValidSubstr[0];
        for(int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i-1] + tempValidSubstr[i];
        }

        vector<long long> result;
        for(vector<int>& query : queries) {
            int low  = query[0];
            int high = query[1];

            int validRightIdx = min(high, rightMost[low]);

            long long length = validRightIdx - low + 1;

            long long tempResult = length * (length+1)/2;

            tempResult += cumSum[high] - cumSum[validRightIdx];

            result.push_back(tempResult);

        }

        return result;

    }
};
