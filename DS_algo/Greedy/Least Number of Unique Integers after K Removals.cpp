class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(int &x : arr) {
            mp[x]++;
        }

        vector<int> freq;

        for(auto &it : mp) {
            freq.push_back(it.second);
        }

        sort(begin(freq), end(freq));

        for(int i = 0; i < freq.size(); i++) {

            k -= freq[i];

            if(k < 0) {
                return freq.size() - i;
            }
        }

        return 0;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(int &x : arr) {
            mp[x]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &it : mp) {
            pq.push(it.second);
        }

        while(!pq.empty()) {

            k -= pq.top();

            if(k < 0) {
                return pq.size();
            }

            pq.pop();
        }

        return 0;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;

        for(int &x : arr) {
            mp[x]++;
        }

        vector<int> freqCount(n+1);

        int uniqueTypes = mp.size();

        for(auto &it : mp) {
            int freq = it.second;
            freqCount[freq]++;
        }

        for(int freq = 1; freq <= n; freq++) {

            int typesICanDelete = min(k/freq, freqCount[freq]);

            k -= (typesICanDelete * freq);

            uniqueTypes -= typesICanDelete;

            if(k <= freq) {
                return uniqueTypes;
            }
        }

        return 0;

    }
};

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> mp = new HashMap<>();

        for (int x : arr) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }

        List<Integer> freq = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            freq.add(entry.getValue());
        }

        Collections.sort(freq);

        for (int i = 0; i < freq.size(); i++) {
            k -= freq.get(i);

            if (k < 0) {
                return freq.size() - i;
            }
        }

        return 0;
    }
}

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {

        Map<Integer, Integer> mp = new HashMap<>();
        for (int i : arr) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(mp.values());

        int elementsRemoved = 0;

        while (!pq.isEmpty()) {

            elementsRemoved += pq.peek();

            if (elementsRemoved > k) {
                return pq.size();
            }
            pq.poll();
        }

        return 0;
    }
}

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        int n = arr.length;

        Map<Integer, Integer> mp = new HashMap<>();

        for (int x : arr) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }

        int[] freqCount = new int[n + 1];

        int uniqueElements = mp.size();

        for (int count : mp.values()) {
            freqCount[count]++;
        }

        for (int freq = 1; freq <= n; freq++) {
            int countUniqueElementsRemove = Math.min(k / freq, freqCount[freq]);

            k -= (freq * countUniqueElementsRemove);

            uniqueElements -= countUniqueElementsRemove;

            if (k <= freq) {
                return uniqueElements;
            }
        }

        return 0;
    }
}
