class Solution {
public:

    void printVector(vector<vector<int> >& vec, int& N ) {
        for(int size = 0; size < N+1; size++) {
            cout << "For size = " << size << " : ";
            for(int j = 0; j<vec[size].size(); j++) {
                cout << vec[size][j] << ", ";
            }
            cout << "\n";
        }
        cout << "\n-------\n";
    }

    int minimumDifference(vector<int>& nums) {
    int n = nums.size();

    int N = n/2;
    int totalSum = accumulate(begin(nums), end(nums), 0);
    vector<vector<int> > left(N+1), right(N+1);

    for(int mask = 0; mask < (1 << N); mask++) {
        int size = 0, leftSum = 0, rigthSum = 0;
        for(int index = 0; index < N; index++) {
            if(mask & (1 << index)) {

                size++;
                leftSum  += nums[index];
                rigthSum += nums[index+N];
            }
        }

        left[size].push_back(leftSum);
        right[size].push_back(rigthSum);
    }

        for (auto &arr : right) {
           sort(begin(arr), end(arr));
       }

       int minDiff = min(abs(totalSum-2*left[N][0]), abs(totalSum-2*right[N][0]));
       for(int leftSize = 1; leftSize < N; leftSize++) {
           for(auto &a : left[leftSize]) {
                int rightSize = N-leftSize;

                int b         = (totalSum - (2*a))/2;

                std::vector<int>::iterator itr = lower_bound(begin(right[rightSize]), end(right[rightSize]), b);

                if(itr != right[rightSize].end()) {
                    minDiff = min(minDiff, abs(totalSum - 2*(a + *itr)));
                }

           }

       }

        return minDiff;

    }
};
