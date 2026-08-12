class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> lessPivot;
        vector<int> equalPivot;
        vector<int> greaterPivot;

        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                lessPivot.push_back(nums[i]);
            } else if(nums[i] == pivot) {
                equalPivot.push_back(nums[i]);
            } else {
                greaterPivot.push_back(nums[i]);
            }
        }

        for(int &num : equalPivot) {
            lessPivot.push_back(num);
        }

        for(int &num : greaterPivot) {
            lessPivot.push_back(num);
        }

        return lessPivot;

    }
};

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int countless  = 0;
        int countequal = 0;

        for(int &num : nums) {
            if(num < pivot)
                countless++;
            else if(num == pivot)
                countequal++;
        }

        int i = 0;
        int j = countless;
        int k = countless + countequal;
        vector<int> result(n);

        for(int &num : nums) {
            if(num < pivot) {
                result[i] = num;
                i++;
            } else if(num == pivot) {
                result[j] = num;
                j++;
            } else {
                result[k] = num;
                k++;
            }
        }

        return result;

    }
};

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> result(n);

        int i = 0;
        int j = n-1;

        int i_ = 0;
        int j_ = n-1;

        while(i < n && j >= 0) {
            if(nums[i] < pivot) {
                result[i_] = nums[i];
                i_++;
            }

            if(nums[j] > pivot) {
                result[j_] = nums[j];
                j_--;
            }

            i++;
            j--;
        }

        while(i_ <= j_) {
            result[i_] = pivot;
            i_++;
        }

        return result;

    }
};

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;

        List<Integer> lessPivot = new ArrayList<>();
        List<Integer> equalPivot = new ArrayList<>();
        List<Integer> greaterPivot = new ArrayList<>();

        for (int num : nums) {
            if (num < pivot) {
                lessPivot.add(num);
            } else if (num == pivot) {
                equalPivot.add(num);
            } else {
                greaterPivot.add(num);
            }
        }

        List<Integer> result = new ArrayList<>();
        result.addAll(lessPivot);
        result.addAll(equalPivot);
        result.addAll(greaterPivot);

        return result.stream().mapToInt(i -> i).toArray();
    }
}

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;

        int countLess = 0;
        int countEqual = 0;

        for (int num : nums) {
            if (num < pivot)
                countLess++;
            else if (num == pivot)
                countEqual++;
        }

        int i = 0;
        int j = countLess;
        int k = countLess + countEqual;
        int[] result = new int[n];

        for (int num : nums) {
            if (num < pivot) {
                result[i] = num;
                i++;
            } else if (num == pivot) {
                result[j] = num;
                j++;
            } else {
                result[k] = num;
                k++;
            }
        }

        return result;
    }
}

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] result = new int[n];

        int i = 0, j = n - 1;
        int i_ = 0, j_ = n - 1;

        while (i < n && j >= 0) {
            if (nums[i] < pivot) {
                result[i_] = nums[i];
                i_++;
            }

            if (nums[j] > pivot) {
                result[j_] = nums[j];
                j_--;
            }

            i++;
            j--;
        }

        while (i_ <= j_) {
            result[i_] = pivot;
            i_++;
        }

        return result;
    }
}
