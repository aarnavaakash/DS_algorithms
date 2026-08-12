class Solution {
public:
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff) {
        int n = A.size();
        int count = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(row+rowOff < 0 || row+rowOff >= n || col+colOff < 0 || col+colOff >= n)
                    continue;

                count += A[row][col]*B[row+rowOff][col+colOff];
            }
        }

        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();

        int maxOverlap = 0;

        for(int rowOff = -n+1; rowOff<n; rowOff++) {
            for(int collOff = -n+1; collOff<n; collOff++) {
                maxOverlap = max(maxOverlap, countOverlaps(A, B, rowOff, collOff));
            }
        }

        return maxOverlap;
    }
};

class Solution {
public:
    int shiftAndCount(vector<vector<int>>& A, vector<vector<int>>& B, int x_shift, int y_shift) {
        int n = A.size();
        int leftShiftCount  = 0;
        int rightShiftCount = 0;

        int A_row = 0;

        for(int B_row = x_shift; B_row<n; B_row++) {
            int A_col = 0;
            for(int B_col = y_shift; B_col<n; B_col++) {
                if(B[B_row][B_col] == 1 && B[B_row][B_col] == A[A_row][A_col])
                    leftShiftCount++;
                if(B[B_row][A_col] == 1 && B[B_row][A_col] == A[A_row][B_col])
                    rightShiftCount++;
                A_col++;
            }
            A_row++;
        }
        return max(leftShiftCount, rightShiftCount);
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {

        int n = A.size();
        int maxOverlap = 0;
        for(int x_shift = 0; x_shift<n; x_shift++) {
            for(int y_shift = 0; y_shift<n; y_shift++) {

                maxOverlap = max(maxOverlap, shiftAndCount(A, B, x_shift, y_shift));

                maxOverlap = max(maxOverlap, shiftAndCount(B, A, x_shift, y_shift));
            }
        }
        return maxOverlap;
    }

};

class Solution {
public:
    int maxOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int count = 0;
        for(int x_shift = 0; x_shift<n; x_shift++) {
            for(int y_shift = 0; y_shift<n; y_shift++) {
                int temp = 0;
                for(int i = y_shift; i<n; i++) {
                    for(int j = x_shift; j<n; j++) {
                        if(A[i][j] == 1 && B[i-y_shift][j-x_shift] == 1)
                            temp++;
                    }
                }
                count = max(count, temp);
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(maxOverlap(A, B), maxOverlap(B, A));
    }
};
