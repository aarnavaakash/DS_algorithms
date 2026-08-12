class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int i = 0;

        while(i < n-1 && arr[i] < arr[i+1])
            i++;

        return i;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int l = 0;
        int r = n-1;

        while(l < r) {

            int mid = l + (r-l)/2;

            if(arr[mid] < arr[mid+1])
                l = mid+1;
            else
                r = mid;

        }

        return l;
    }
};
