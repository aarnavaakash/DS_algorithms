class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;

        int drank = numBottles;

        while(empty >= numExchange) {
            empty -= numExchange;

            drank++;

            empty++;

            numExchange++;
        }

        return drank;
    }
};

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return numBottles + ((-2*numExchange + 3 + sqrt(4*numExchange*numExchange+8*numBottles - 12 * numExchange + 1))/2);
    }
};
