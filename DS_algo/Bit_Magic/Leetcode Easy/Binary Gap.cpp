class Solution {
public:
    int binaryGap(int n) {
        int curr = 0;
        int prev = -1;

        int result = 0;

        while(n > 0) {
            if((n&1) > 0) {
                result = (prev != -1) ? max(result, curr - prev) : result;
                prev = curr;
            }

            curr++;
            n >>= 1;
        }

        return result;
    }
};

class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;

        int result = 0;

        for(int curr = 0; curr < 32; curr++) {
            if(((n >> curr) & 1) > 0) {
                result = (prev != -1) ? max(result, curr-prev) : result;
                prev = curr;
            }
        }

        return result;
    }
};
