class Solution {
public:
    void backtrack(int low, int high, int start, vector<int>& result) {
        if(start == 9)
            return;
        if(start%10 < 9) {
            start = start * 10 + (start%10) + 1;

            if(start>=low && start<=high)
                result.push_back(start);
            backtrack(low, high, start, result);
        } else {

            int num_digits = log10(start);
            int MSD = start/pow(10, num_digits);
            backtrack(low, high, MSD+1, result);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        backtrack(low, high, 1, result);
        sort(result.begin(), result.end());
        return result;
    }
};

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";

        vector<int> result;
        for(int i = 0; i<9; i++) {
            for(int j = i+1; j<9; j++) {
                string temp = s.substr(i, j-i+1);

                int num = stoi(temp);
                if(num > high) break;

                if(num >= low && num <= high)
                    result.push_back(num);
            }
        }

        sort(begin(result), end(result));
        return result;
    }
};
