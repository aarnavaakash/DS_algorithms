class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(begin(arr), end(arr), 0);

        if(sum == 0)
            return {0, n-1};
        else if(sum%3 != 0)
            return {-1, -1};

        int k = sum/3;

        int start = -1, mid = -1, end = -1;
        int count = 0;

        for(int i = 0; i<n; i++) {
            if(arr[i] == 0) continue;

            count += arr[i];
            if(count > k) {
                count = 1;
            }

            if(count == 1) {
                if(start == -1) start = i;
                else if(mid == -1) mid = i;
                else if(end == -1) end = i;
                else break;
            }
        }

        while(end < n && arr[start] == arr[mid] && arr[mid] == arr[end]) {
            start++;  mid++;   end++;
        }

        if(end != n)  return {-1, -1};

        return {start-1, mid};
    }
};
