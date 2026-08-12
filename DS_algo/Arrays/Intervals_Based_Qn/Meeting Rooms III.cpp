class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings), end(meetings));

        vector<int> roomsUsedCount(n, 0);
        vector<long long> lastAvailableAt(n, 0);

        for(vector<int>& meet : meetings) {
            int start  = meet[0];
            int end    = meet[1];
            bool found = false;

            long long EarlyEndRoomTime = LLONG_MAX;
            int EarlyEndRoom     = 0;

            for(int room = 0; room < n; room++) {
                if(lastAvailableAt[room] <= start) {
                    found = true;
                    lastAvailableAt[room] = end;
                    roomsUsedCount[room]++;
                    break;
                }

                if(lastAvailableAt[room] < EarlyEndRoomTime) {
                    EarlyEndRoom = room;
                    EarlyEndRoomTime = lastAvailableAt[room];
                }
            }

            if(!found) {
                lastAvailableAt[EarlyEndRoom] += (end - start);
                roomsUsedCount[EarlyEndRoom]++;
            }

        }

        int resultRoom = -1;
        int maxUse     = 0;
        for(int room = 0; room < n; room++) {
            if(roomsUsedCount[room] > maxUse) {
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};

class Solution {
public:
    typedef pair<long long, int> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings), end(meetings));

        vector<int> roomsUsedCount(n, 0);

        priority_queue<P, vector<P>, greater<P>> usedRooms;

        priority_queue<int, vector<int>, greater<int>> unusedRooms;

        for(int room = 0; room < n; room++) {
            unusedRooms.push(room);
        }

        for(vector<int>& meet : meetings) {
            int start  = meet[0];
            int end    = meet[1];

            while(!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }

            if(!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                roomsUsedCount[room]++;
            } else {
                int room          = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + (end-start), room});
                roomsUsedCount[room]++;
            }

        }

        int resultRoom = -1;
        int maxUse     = 0;
        for(int room = 0; room < n; room++) {
            if(roomsUsedCount[room] > maxUse) {
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};
