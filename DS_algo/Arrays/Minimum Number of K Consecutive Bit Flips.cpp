class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        vector<bool> isFlipped(n, false);
        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k && isFlipped[i-k] == true){
                flipCountFromPastForCurri--;
            }

            if(flipCountFromPastForCurri % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipCountFromPastForCurri++;
                isFlipped[i] = true;
                flips++;
            }
        }

        return flips;
    }
};

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;

        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {

            if(i >= k && nums[i-k] == 2) {
                flipCountFromPastForCurri--;
            }

            if(flipCountFromPastForCurri % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipCountFromPastForCurri++;
                nums[i] = 2;
                flips++;
            }
        }

        return flips;
    }
};

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        deque<int> flipQue;
        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k){
                flipCountFromPastForCurri -= flipQue.front();
                flipQue.pop_front();
            }

            if(flipCountFromPastForCurri % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipCountFromPastForCurri++;
                flipQue.push_back(1);
                flips++;
            } else {
                flipQue.push_back(0);
            }
        }

        return flips;
    }
};
