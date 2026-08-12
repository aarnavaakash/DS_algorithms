class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && arr[i] == 2*arr[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            if(st.find(arr[i]*2) != st.end()) {
                return true;
            } else if(arr[i]%2 == 0 && st.find(arr[i]/2) != st.end()) {
                return true;
            }
            st.insert(arr[i]);
        }

        return false;
    }
};

class Solution {
public:
    int bSearch(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size()-1;

        int mid;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(arr[mid] == target) {
                return mid;
            } else if(arr[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return -1;
    }

    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        for(int i = 0; i < n; i++) {
            int j = bSearch(arr, 2*arr[i]);

            if(j != -1 && j != i) {
                return true;
            }
        }

        return false;

    }
};

class Solution {
    public boolean checkIfExist(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }

        return false;
    }
}

class Solution {
    public boolean checkIfExist(int[] arr) {
        int n = arr.length;
        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < n; i++) {

            if (set.contains(arr[i] * 2)) {
                return true;
            }

            else if (arr[i] % 2 == 0 && set.contains(arr[i] / 2)) {
                return true;
            }

            set.add(arr[i]);
        }

        return false;
    }
}

class Solution {

    public int bSearch(int[] arr, int target) {
        int l = 0;
        int r = arr.length - 1;
        int mid;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }

    public boolean checkIfExist(int[] arr) {
        int n = arr.length;

        Arrays.sort(arr);

        for (int i = 0; i < n; i++) {

            int j = bSearch(arr, 2 * arr[i]);

            if (j != -1 && j != i) {
                return true;
            }
        }

        return false;
    }
}
