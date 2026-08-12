class Solution {
public:
    int getReverse(int n) {
        int result = 0;

        while (n) {
            int rem = n%10;
            result  = (result * 10) + rem;
            n      /= 10;
        }

        return result;
    }

    int mirrorDistance(int n) {
        return abs(n - getReverse(n));
    }
};

class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(begin(s), end(s));

        int rev = stoi(s);
        return abs(n - rev);
    }
};
