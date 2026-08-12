class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int n = arr.size();

        for(int i = 0; i < n-2; i++) {
            if(arr[i]%2 && arr[i+1]%2 && arr[i+2]%2) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int n = arr.size();
        int oddCount = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 == 1) {
                oddCount++;
            } else {
                oddCount = 0;
            }

            if(oddCount == 3)
                return true;
        }
        return false;
    }
};
