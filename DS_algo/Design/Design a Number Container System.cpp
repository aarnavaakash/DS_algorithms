class NumberContainers {
public:

    unordered_map<int, int> idxToNum;
    unordered_map<int, set<int>> numToIdx;

    NumberContainers() {

    }

    void change(int index, int number) {
        if(idxToNum.count(index)) {
            int prevNum = idxToNum[index];
            numToIdx[prevNum].erase(index);
            if(numToIdx[prevNum].empty()) {
                numToIdx.erase(prevNum);
            }
        }

        idxToNum[index] = number;
        numToIdx[number].insert(index);

    }

    int find(int number) {
        if(numToIdx.count(number)) {
            return *numToIdx[number].begin();
        }

        return -1;
    }
};

class NumberContainers {
public:

    unordered_map<int, int> idxToNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx;

    NumberContainers() {

    }

    void change(int index, int number) {
        idxToNum[index] = number;

        numToIdx[number].push(index);
    }

    int find(int number) {
        if(!numToIdx.count(number)) {
            return -1;
        }

        auto& pq = numToIdx[number];

        while(!pq.empty()) {
            int idx = pq.top();

            if(idxToNum[idx] == number) {
                return idx;
            }

            pq.pop();
        }

        return -1;
    }
};
