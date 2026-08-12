class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        sort(begin(arr), end(arr));

        int d = arr[1] - arr[0];

        for(int i = 2; i<n; i++) {
            if(arr[i] - arr[i-1] != d)
                return false;
        }

        return true;
    }
};

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> st(begin(arr), end(arr));

        int min_el = *min_element(begin(arr), end(arr));
        int max_el = *max_element(begin(arr), end(arr));

        if((max_el - min_el)%(n-1))
            return false;

        int d = (max_el - min_el)/(n-1);

        int i = 0;

        while(i < n) {
            int num = min_el + i*d;
            if(st.find(num) == st.end())
                return false;

            i++;
        }

        return true;
    }
};

class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {

        int n = arr.size();

        int min_el = *min_element(begin(arr), end(arr));
        int max_el = *max_element(begin(arr), end(arr));

        if((max_el - min_el)%(n-1) != 0)
            return false;

        int d = (max_el - min_el)/(n-1);

        int i = 0;
        while (i < n) {
            if(arr[i] == min_el + i*d) {
                i++;
            } else {

                if((arr[i] - min_el) % d != 0)
                    return false;

                int j = (arr[i] - min_el)/d;

                if(arr[i] == arr[j])
                    return false;

                swap(arr[i], arr[j]);

            }
        }

        return true;
    }
};
