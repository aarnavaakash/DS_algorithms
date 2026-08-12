class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        for(int i = 31; i>=0; i--) {
            if(((n >> i) & 1) == 1) {
                count++;
            }
        }

        return count;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n) {
            n = (n&(n-1));
            count++;
        }

        return count;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n) {
            count += (n%2);
            n /= 2;
        }

        return count;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
