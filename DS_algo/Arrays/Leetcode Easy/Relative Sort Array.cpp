class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;

        for(int &num : arr1) {
            mp[num]++;
        }

        int i = 0;
        for(int &num : arr2) {
            while(mp[num]-- > 0) {
                arr1[i++] = num;
            }
        }

        for(auto &it : mp) {
            int freq = it.second;
            while(freq > 0) {
                arr1[i++] = it.first;
                freq--;
            }
        }

        return arr1;
    }
};

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;

        for(int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
        }

        for(int &num : arr1) {
            if(!mp.count(num)) {
                mp[num] = 1e9;
            }
        }

        auto lambda = [&](int &num1, int &num2){
            if(mp[num1] == mp[num2]) {
                return num1 < num2;
            }

            return mp[num1] < mp[num2];
        };

        sort(begin(arr1), end(arr1), lambda);

        return arr1;
    }
};

class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {

        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : arr1) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }

        List<Integer> result = new ArrayList<>();

        for (int num : arr2) {
            if (countMap.containsKey(num)) {
                for (int i = 0; i < countMap.get(num); i++) {
                    result.add(num);
                }

                countMap.remove(num);
            }
        }

        List<Integer> remaining = new ArrayList<>();
        for (int num : countMap.keySet()) {
            for (int i = 0; i < countMap.get(num); i++) {
                remaining.add(num);
            }
        }
        Collections.sort(remaining);
        result.addAll(remaining);

        int[] resultArray = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            resultArray[i] = result.get(i);
        }

        return resultArray;
    }
}

class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr2.length; i++) {
            map.put(arr2[i], i);
        }

        int largeValue = 1000000000;
        for (int i = 0; i < arr1.length; i++) {
            if (!map.containsKey(arr1[i])) {
                map.put(arr1[i], largeValue);
            }
        }

        Comparator<Integer> comparator = (num1, num2) -> {
            int index1 = map.get(num1);
            int index2 = map.get(num2);
            if (index1 == index2) {
                return Integer.compare(num1, num2);
            }
            return Integer.compare(index1, index2);
        };

        List<Integer> arr1List = new ArrayList<>();
        for (int num : arr1) {
            arr1List.add(num);
        }

        Collections.sort(arr1List, comparator);

        int[] sortedArray = new int[arr1.length];
        for (int i = 0; i < arr1.length; i++) {
            sortedArray[i] = arr1List.get(i);
        }

        return sortedArray;
    }
}
