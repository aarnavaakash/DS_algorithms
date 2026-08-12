class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int sum_A = 0;
        int sum_B = 0;
        sort(B, B+m);

        for(int i = 0; i<n; i++) {
            sum_A += A[i];
        }

        for(int i = 0; i<m; i++) {
            sum_B += B[i];
        }

        int diff = (sum_A - sum_B);

        if(diff%2 == 1)
            return -1;

        diff = diff/2;

        for(int i = 0; i<n; i++) {
            int search = (A[i] - diff);
            int l = 0, h = m-1;
            while(l < h) {
                int mid = l + (h-l)/2;
                if(B[mid] == search) {
                    return 1;
                } else if(B[mid] > search) {
                    h = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }

        return -1;
	}

};

class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int sum_A = 0;
        int sum_B = 0;
        unordered_set<int> st;
        for(int i = 0; i<n; i++) {
            sum_A += A[i];
        }

        for(int i = 0; i<m; i++) {
            sum_B += B[i];
            st.insert(B[i]);
        }

        int diff = (sum_A - sum_B);

        if(diff%2 == 1)
            return -1;

        diff = diff/2;

        for(int i = 0; i<n; i++) {
            int search = (A[i] - diff);
            if(st.find(search) != st.end())
                return 1;
        }

        return -1;
	}

};
