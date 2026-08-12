class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int result = k;

        for (int i = 0; i <= n - k; i++) {
            int W = 0;
            for (int j = i; j-i+1 <= k; j++) {
                if (blocks[j] == 'W') {
                    W++;
                }
            }
            result = min(result, W);
        }

        return result;
    }
};

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0;
        int j = 0;

        int ops = k;
        int W = 0;

        while(j < n) {
            if(blocks[j] == 'W') {
                W++;
            }

            if(j - i + 1 == k) {
                ops = min(ops, W);

                if(blocks[i] == 'W') {
                    W--;
                }
                i++;
            }
            j++;
        }

        return ops;
    }
};
