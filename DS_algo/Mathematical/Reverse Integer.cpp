class Solution {
public:
    int reverse(int x) {
        int reverse = 0;

        while(x) {
            int remain = x%10;

            if(reverse > INT_MAX/10 || (reverse == INT_MAX/10 && remain > 7)) {
                return 0;
            }

            if(reverse < INT_MIN/10 || (reverse == INT_MIN/10 && remain < -8)) {
                return 0;
            }

            reverse *= 10;
            reverse += remain;
            x = x/10;
        }

        return reverse;
    }
};
