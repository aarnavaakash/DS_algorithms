************************************************************ C++ ************************************************************

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minh;

        for(int i:nums) {
            minh.push(i);
            if(minh.size() > k)
                minh.pop();
        }

        return minh.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>());
        return nums[k - 1];
    }
};

class Solution {
public:

    int partition_algo(vector<int>& nums, int L, int R) {

        int P = nums[L];
        int i = L+1;
        int j = R;

        while(i <= j) {

            if(nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            if(nums[i] >= P) {
                i++;
            }

            if(nums[j] <= P) {
                j--;
            }

        }

        swap(nums[L], nums[j]);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        int L = 0;
        int R = n-1;

        int pivot_idx = 0;

        while(true) {

             pivot_idx = partition_algo(nums, L, R);

            if(pivot_idx == k-1) {
                break;
            } else if(pivot_idx > k-1) {
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }

        }

        return nums[pivot_idx];

    }
};

************************************************************ JAVA ************************************************************

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minh = new PriorityQueue<>();
        for (int num: nums) {
            minh.add(num);
            if (minh.size() > k) {
                minh.remove();
            }
        }

        return minh.peek();
    }
}

class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length - k];
    }
}

class Solution {

    private void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }

    public int partition_algo(int[] nums, int L, int R) {

        int P = nums[L];
        int i = L+1;
        int j = R;

        while(i <= j) {

            if(nums[i] < P && nums[j] > P) {
                swap(nums, i, j);
                i++;
                j--;
            }

            if(nums[i] >= P) {
                i++;
            }

            if(nums[j] <= P) {
                j--;
            }

        }

        swap(nums, L, j);
        return j;
    }

    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;

        int L = 0;
        int R = n-1;

        int pivot_idx = 0;

        while(true) {

            pivot_idx = partition_algo(nums, L, R);

            if(pivot_idx == k-1) {
                break;
            } else if(pivot_idx > k-1) {
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }

        }

        return nums[pivot_idx];
    }
}
