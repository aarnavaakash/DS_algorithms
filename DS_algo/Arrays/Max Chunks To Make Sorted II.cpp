class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> rightMin(n);
        rightMin[n-1] = arr[n-1];

        for(int i = n-2; i>=0; i--)
            rightMin[i] = min(rightMin[i+1], arr[i]);

        int leftMax = arr[0];

        int count = 0;

        for(int i = 0; i<n-1; i++) {
            leftMax = max(leftMax, arr[i]);
            if(leftMax <= rightMin[i+1])
                count++;
        }

        return count+1;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted(arr);
        sort(begin(sorted), end(sorted));

        vector<int> MAX(n);
        MAX[0] = arr[0];
        for(int i = 1; i<n; i++)
            MAX[i] = max(MAX[i-1], arr[i]);

        int rightMax = MAX[n-1];
        int count    = 0;
        for(int  i = n-1; i>=0; i--) {
            if(sorted[i] == MAX[i]) {
                if(sorted[i] > rightMax)
                    continue;

                rightMax = arr[i];
                count++;
            }
        }

        return count;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted(arr);
        sort(begin(sorted), end(sorted));

        long long sum1 = 0, sum2 = 0;
        int count = 0;
        for(int i = 0; i<n; i++) {
            sum1 += arr[i];
            sum2 += sorted[i];

            if(sum1 == sum2)
                count++;
        }

        return count;
    }
};
