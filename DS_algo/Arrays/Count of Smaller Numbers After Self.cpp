class Solution {
public:
    typedef pair<int, int> P;
    vector<int> Count;
    void merge(vector<pair<int, int>>& nums, int l, int mid, int r) {
        vector<pair<int, int>> temp(r-l+1);
        int i = l, j = mid+1, k = 0;

        while(i <= mid && j <= r) {
            if(nums[i].first <= nums[j].first) {
                temp[k] = nums[j];
                j++;
            } else {
                Count[nums[i].second] += r-j+1;

                temp[k] = nums[i];
                i++;
            }
            k++;
        }

        while (i <= mid) {
                temp[k++] = nums[i++];
        }
        while (j <= r) {
            temp[k++] = nums[j++];
        }
        for (int i = l; i <= r; i++)
            nums[i] = temp[i-l];
    }

    void mergeSortUsingIndex(vector<pair<int, int>>& nums, int l, int r) {
        if(l >= r)
            return;

        int mid = l + (r-l)/2;
        mergeSortUsingIndex(nums, l, mid);
        mergeSortUsingIndex(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        Count.resize(n, 0);
        vector<P> vec(n);

        for(int i = 0; i<n; i++) {
            vec[i] = {nums[i], i};
        }

        mergeSortUsingIndex(vec, 0, n-1);

        return Count;
    }
};

class Solution {
public:
    typedef pair<int, int> P;
    typedef vector<P>::iterator itr;
    vector<int> count;

    void mergeSort(vector<P>& nums, itr start, itr end) {
        if(end-start <= 1)
            return;

        auto mid = start + (end-start)/2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid, end);

        for(auto i = start, j = mid; i!= mid; i++) {
            while(j != end && i->first > j->first) {
                j++;
            }
            count[i->second] += j-mid;
        }

        inplace_merge(start, mid, end);
    }

    vector<int> countSmaller(vector<int>& vec) {
        int n = vec.size();
        vector<P> nums(n);
        count.resize(n, 0);

        for(int i = 0; i<n; i++) {
            nums[i] = make_pair(vec[i], i);
        }

        mergeSort(nums, begin(nums), end(nums));

        return count;

    }
};
