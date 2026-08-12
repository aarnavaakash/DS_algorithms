class Solution {
public:

    int countSum(int x) {
        int count = 0;
        int temp = x;
        for(int i = 2; i * i <= temp; i++) {

            while(x%i == 0) {
                x /= i;
                count++;
            }

        }
        if(x != 1) {
            count++;
        }
        return count;
    }

	int sumOfPowers(int a, int b){
	    int result = 0;

	    while(a <= b) {
	        result += countSum(a);
	        a++;
	    }
	    return result;
	}
};
