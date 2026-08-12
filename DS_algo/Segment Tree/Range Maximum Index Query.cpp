class Solution {
public:

    void buildSegmentTree(int i, int l, int r, int segmentTree[], vector<int>& arr) {
        if (l == r) {
            segmentTree[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);

        segmentTree[i] = (arr[segmentTree[2 * i + 1]] >= arr[segmentTree[2 * i + 2]]) ?
                        segmentTree[2 * i + 1] : segmentTree[2 * i + 2];
    }

    int* constructST(vector<int>& arr, int n) {
        int* segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, arr);
        return segmentTree;
    }

    int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[], vector<int>& arr) {
        if (l > end || r < start) {
            return -1;
        }

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, arr);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, arr);

        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        return (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
    }

    int RMIQ(int st[], vector<int>& arr, int n, int a, int b) {
        return querySegmentTree(a, b, 0, 0, n - 1, st, arr);
    }

    vector<int> rangeMaximumIndexQuery(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int* segmentTree = constructST(arr, n);

        vector<int> result;
        for(auto& query: queries){
            int a = query[0];
            int b = query[1];

            int idx = RMIQ(segmentTree, arr, n, a, b);
            result.push_back(idx);
        }
        return result;
    }
};
