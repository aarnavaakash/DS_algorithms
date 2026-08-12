class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || i == k) {
                        continue;
                    }

                    int num = digits[i]*100 + digits[j] * 10 + digits[k];

                    if(num >= 100 && num%2 == 0) {
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> result(begin(st), end(st));
        sort(begin(result), end(result));
        return result;
    }
};

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        vector<int> mp(10, 0);

        for(int &digit : digits) {
            mp[digit]++;
        }

        for(int i = 1; i <= 9; i++) {
            if(mp[i] == 0) continue;
            mp[i]--;
            for(int j = 0; j <= 9; j++) {
                if(mp[j] == 0) continue;
                mp[j]--;
                for(int k = 0; k <= 8; k += 2) {
                    if(mp[k] == 0) continue;
                    mp[k]--;

                    int num = i*100 + j*10 + k;
                    result.push_back(num);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return result;
    }
};

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        Set<Integer> set = new HashSet<>();
        int n = digits.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k) {
                        continue;
                    }

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                    if (num >= 100 && num % 2 == 0) {
                        set.add(num);
                    }
                }
            }
        }

        List<Integer> resultList = new ArrayList<>(set);
        Collections.sort(resultList);

        int[] result = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            result[i] = resultList.get(i);
        }

        return result;
    }
}

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        List<Integer> result = new ArrayList<>();
        int[] freq = new int[10];

        for (int digit : digits) {
            freq[digit]++;
        }

        for (int i = 1; i <= 9; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;

            for (int j = 0; j <= 9; j++) {
                if (freq[j] == 0) continue;
                freq[j]--;

                for (int k = 0; k <= 8; k += 2) {
                    if (freq[k] == 0) continue;
                    freq[k]--;

                    int num = i * 100 + j * 10 + k;
                    result.add(num);

                    freq[k]++;
                }

                freq[j]++;
            }

            freq[i]++;
        }

        Collections.sort(result);
        int[] resArr = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            resArr[i] = result.get(i);
        }

        return resArr;
    }
}
