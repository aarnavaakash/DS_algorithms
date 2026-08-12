class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> endTimes(n, -1);

        int targetArrivalTime = times[targetFriend][0];

        sort(begin(times), end(times));

        for(vector<int> &time : times) {
            int arrival = time[0];
            int depart  = time[1];

            for(int i = 0; i<n; i++) {
                if(endTimes[i] <= arrival) {
                    endTimes[i] = depart;

                    if(arrival == targetArrivalTime)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    typedef pair<int, int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size();
        priority_queue<P, vector<P>, greater<P> > occupied;
        priority_queue<int, vector<int>, greater<int>> free;

        int targetFriendArrival = times[targetFriend][0];

        sort(times.begin(),times.end());

		int chairNo = 0;

        for(int i = 0; i < n; i++) {
            int arrival  = times[i][0];
            int depart   = times[i][1];

            while(!occupied.empty() && occupied.top().first <= arrival) {
                free.push(occupied.top().second);
                occupied.pop();
            }

            if(free.empty()) {
                occupied.push({depart, chairNo});

                if(arrival == targetFriendArrival)
                    return chairNo;

                chairNo++;
            } else {
                int leastChairAvailable = free.top();
                free.pop();
                if(arrival == targetFriendArrival) {
                    return leastChairAvailable;
                }
                occupied.push({depart, leastChairAvailable});
            }
        }

        return -1;
    }

};

class Solution {
public:
    typedef pair<int, int> p;
    priority_queue<p, vector<p>, greater<p>> pq;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        int targetArrivalTime = times[targetFriend][0];

        sort(begin(times), end(times));

        set<int> chairNum;

        int lastChair = 0;

        for(vector<int> &time : times) {
            int arrival  = time[0];
            int depart   = time[1];
            int currSeat = -1;

            while(!pq.empty() && pq.top().first <= arrival) {
                chairNum.insert(pq.top().second);
                pq.pop();
            }

            if(chairNum.empty()) {
                currSeat = lastChair;
                lastChair++;
            } else {
                currSeat = *(chairNum.begin());
                chairNum.erase(currSeat);
            }
            pq.push({depart, currSeat});
            if(arrival == targetArrivalTime)
                return currSeat;
        }

        return -1;
    }
};
