class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest/minutesToDie + 1;

        int pigs = 0;

        while(pow(T, pigs) < buckets) {
            pigs++;
        }

        return pigs;

    }
};

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {

        return ceil(log2(buckets)/log2(minutesToTest/minutesToDie + 1));

    }
};
