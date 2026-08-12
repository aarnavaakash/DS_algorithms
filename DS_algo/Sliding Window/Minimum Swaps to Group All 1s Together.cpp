class Solution {
public:
    int totalOnes(vector<int>& arr) {
        int count = 0;
        for(int i = 0; i<arr.size(); i++) {
          if(arr[i] == 1)
              count++;
        }
        return count;
    }
    int minSwaps(vector<int>& data) {
        if(n == 1){
            return arr[0]==1?0:-1;
        }
        int windowSize = totalOnes(arr);

        if(windowSize == 0) return -1;

        int zeros = 0;
        for(int i = 0; i<windowSize; i++) {
            if(arr[i] == 0)
                zeros++;
        }

        int minZeros = zeros;

        int i = 1, j = windowSize;
        while(j < n) {
            if(arr[i-1] == 0)
                zeros--;
            if(arr[j] == 0)
                zeros++;
            minZeros = min(minZeros, zeros);
            j++;
            i++;
        }
        return minZeros;
    }
};
