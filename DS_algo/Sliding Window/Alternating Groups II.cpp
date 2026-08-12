class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            bool isAlternating = true;
            for (int j = i; j < i + k - 1; j++) {
                if (colors[j] == colors[j + 1]) {
                    isAlternating = false;
                    break;
                }
            }
            if (isAlternating) {
                result++;
            }
        }

        return result;
    }
};

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int N = n + (k-1);
        for(int i = 0; i < k-1; i++) {
            colors.push_back(colors[i]);
        }

        int result = 0;
        int i = 0;
        int j = 1;
        while(j < N) {
            if(colors[j] == colors[j-1]) {
                i = j;
                j++;
                continue;
            }

            if(j - i + 1 == k) {
                result++;
                i++;
            }

            j++;
        }

        return result;
    }
};

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int result = 0;

        int length = 1;
        int last   = colors[0];

        for(int i = 1; i < n; i++) {
            if(colors[i] == last) {
                length = 1;
                last = colors[i];
                continue;
            }

            length++;

            if(length >= k) {
                result++;
            }

            last = colors[i];
        }

        for(int i = 0; i < k-1; i++) {
            if(colors[i] == last) {
                length = 1;
                last = colors[i];
                break;
            }

            length++;

            if(length >= k) {
                result++;
            }

            last = colors[i];
        }

        return result;

    }
};
