class Router {
private:
    int MAX_SIZE;
    unordered_map<string, vector<int>> packetStore;
    unordered_map<int, vector<int>> destTimestamps;
    queue<string> que;

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (packetStore.find(key) != packetStore.end()) {
            return false;
        }

        if ((int)packetStore.size() >= MAX_SIZE) {
            forwardPacket();
        }

        packetStore[key] = {source, destination, timestamp};
        que.push(key);
        destTimestamps[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty())
            return {};

        string key = que.front();
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        destTimestamps[dest].erase(destTimestamps[dest].begin());

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end() || it->second.empty())
            return 0;

        int i = lower_bound(begin(it->second), end(it->second), startTime) - begin(it->second);
        int j = upper_bound(begin(it->second), end(it->second), endTime) - begin(it->second);

        return j - i;
    }
};
