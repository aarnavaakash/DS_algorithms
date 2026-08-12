class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();

        sort(begin(piles), end(piles));

        int result = 0;

        int Bob = 0, Me = n-2, Alice = n-1;

        while(Me > Bob) {

            result += piles[Me];

            Me    -= 2;
            Bob   += 1;
            Alice -= 2;
        }

        return result;
    }
};

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();

        sort(begin(piles), end(piles));

        int result = 0;

        for(int i = n/3; i <n; i+=2) {
            result += piles[i];
        }

        return result;
    }
};
