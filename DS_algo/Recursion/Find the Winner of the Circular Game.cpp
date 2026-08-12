class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        int i = 0;

        while(arr.size() > 1) {
            int idx = (i + k - 1) % arr.size();

            arr.erase(arr.begin() + idx);

            i = idx;
        }

        return arr[0];
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        for(int i = 1; i <= n; i++) {
            que.push(i);
        }

        while(que.size() > 1) {

            for(int count = 1; count <= k-1; count++) {
                que.push(que.front());
                que.pop();
            }

            que.pop();

        }

        return que.front();
    }
};

class Solution {
public:

    int findWinnerIdx(int n, int k) {
        if(n == 1) {
            return 0;
        }

        int idx = findWinnerIdx(n-1, k);
        idx = (idx + k) % n;

        return idx;
    }

    int findTheWinner(int n, int k) {

        int result_idx = findWinnerIdx(n, k);

        return result_idx + 1;

    }
};
