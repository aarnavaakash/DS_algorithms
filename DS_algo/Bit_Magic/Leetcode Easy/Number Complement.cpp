class Solution {
public:
    int findComplement(int num) {
        int number_of_bits = (int)(log2(num)) + 1;

        for(int i = 0; i<number_of_bits; i++) {
            num = num^(1<<i);
        }
        return num;
    }
};

class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;

        int number_of_bits = (int)(log2(num)) + 1;

        unsigned int mask = (1U << numBits) - 1;

        return num ^ mask;
    }
};

class Solution {
public:
    int findComplement(int num) {
        int i = 0, ans = 0;
        while (num) {

            if (!(num & 1))
                ans |= (1 << i);
            num >>= 1;
            i++;
        }
        return ans;
    }
};
