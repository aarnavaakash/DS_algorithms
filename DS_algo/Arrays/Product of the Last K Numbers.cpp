class ProductOfNumbers {
public:
    vector<int> nums;
    int n;
    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }

    void add(int num) {
        nums.push_back(num);
    }

    int getProduct(int k) {
        int prod = 1;
        int n = nums.size();

        for(int i = n-k; i < n; i++) {
            prod *= nums[i];
        }

        return prod;
    }
};

class ProductOfNumbers {
public:
    vector<int> nums;
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }

    void add(int num) {
        if(num == 0) {
            nums = {};
            n = 0;
        } else {
            if(nums.empty()) {
                nums.push_back(num);
            } else {
                nums.push_back(nums[n-1] * num);
            }
            n++;
        }
    }

    int getProduct(int k) {
        if(k > n) {
            return 0;
        } else if(k == n) {
            return nums[n-1];
        }

        return nums[n-1] / nums[n-k-1];
    }
};
