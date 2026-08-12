class MyHashMap {
public:
    vector<int> vec;
    int sz;

    MyHashMap() {
        sz = 1e6+1;

        vec.resize(sz);

        fill(vec.begin(), vec.end(), -1);
    }

    void put(int key, int value) {
       vec[key] = value;
    }

    int get(int key) {
       return vec[key] ;
    }

    void remove(int key) {
      vec[key]  =-1;
    }
};

class MyHashMap {
public:

    vector<list<pair<int, int>>> bucket;
    int size = 10000;
    MyHashMap() {
        bucket.resize(size);
    }

    void put(int key, int value) {
        int bucket_no = key%size;
        auto& chain = bucket[bucket_no];
        for(auto& it:chain) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }

    int get(int key) {
        int bucket_no = key%size;
        auto& chain = bucket[bucket_no];
        if(chain.empty())
            return -1;

        for(auto& it:chain) {
            if(it.first == key)
                return it.second;
        }
        return -1;
    }

    void remove(int key) {
        int bucket_no = key%size;
        auto& chain = bucket[bucket_no];

        for (auto it=chain.begin(); it!=chain.end(); ) {
            if(it->first == key) {
                chain.erase(it);
                return;
            }
            it++;
        }

    }
};
