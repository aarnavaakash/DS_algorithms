class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (colors[i] != colors[j]) {
                    result = max(result, j - i);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j > i; j--) {
                if (colors[i] != colors[j]) {
                    result = max(result, j - i);
                    break;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int result = 0;

        int i = 0;
        while(colors[i] == colors[n-1]) i++;

        result = max(result, abs(i - (n-1)));

        i = n-1;
        while(colors[0] == colors[i]) i--;

        result = max(result, i);

        return result;
    }
};

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int result = 0;

       for(int i = 0; i < n; i++) {
            if(colors[i] != colors[0]) {
                result = max(result, i);
            }

            if(colors[i] != colors[n-1]) {
                result = max(result, abs(i - (n-1)));
            }
       }

       return result;
    }
};
