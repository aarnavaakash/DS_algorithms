class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(begin(capacity), end(capacity), greater<int>());

        int totalApple = accumulate(begin(apple), end(apple), 0);

        int count = 0;
        int i = 0;
        while(totalApple > 0) {
            totalApple -= capacity[i];
            count++;
            i++;
        }

        return count;
    }
};

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = accumulate(begin(apple), end(apple), 0);

        vector<int> freq(51, 0);
        for (int cap : capacity) {
            freq[cap]++;
        }

        int count = 0;

        for (int cap = 50; cap >= 1 && totalApple > 0; cap--) {
            while (freq[cap] > 0 && totalApple > 0) {
                totalApple -= cap;
                freq[cap]--;
                count++;
            }
        }

        return count;
    }
};
