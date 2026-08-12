class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;

        int freq = n / 4;

        for (int &num : arr) {
            mp[num]++;
            if (mp[num] > target) {
                return num;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int freq = n/4;

        for(int i = 0; i<n-freq; i++) {

            if(arr[i] == arr[i+freq]) {
                return arr[i];
            }

        }
        return -1;
    }
};

class Solution {
public:

    int firstOccur(int target, int l, int r, vector<int>& arr) {

        int result = -1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(arr[mid] == target) {
                result = mid;
                r = mid-1;
            } else if(arr[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;

    }

    int lastOccur(int target, int l, int r, vector<int>& arr) {

        int result = -1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(arr[mid] == target) {
                result = mid;
                l = mid+1;
            } else if(arr[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;

    }

    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        int freq = n/4;

        vector<int> candidates{arr[n/4], arr[n/2], arr[3*n/4]};

        for(int &candidate : candidates) {

            int left = firstOccur(candidate, 0, n-1, arr);
            int right = lastOccur(candidate, 0, n-1, arr);

            if(right-left+1 > freq) {
                return candidate;
            }
        }

        return -1;

    }
};
