class Solution {
public:
    static bool sortComp(Interval& i1, Interval& i2) {
        return i1.start < i2.start;
    }
    struct Compare {
        bool operator() (Interval& i1, Interval& i2) {

            return i1.end > i2.end;
        }
    };
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size();
        if(n <= 1)
            return n;

        sort(begin(intervals), end(intervals), sortComp);

        priority_queue<Interval, vector<Interval>, Compare> pq;
        pq.push(intervals[0]);

        for(int i = 1; i<n; i++) {

            Interval top = pq.top();
            Interval curr = intervals[i];

            if(top.end > curr.start) {
                pq.push(curr);
            } else {
                pq.pop();
                pq.push(curr);
            }
        }

        return (int) pq.size();
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size();
        if(n <= 1)
            return n;

        vector<int> startTime(n);
        vector<int> endTime(n);

        int i = 0;
        for(const Interval& interval : intervals) {
        	startTime[i] = interval.start;
        	endTime[i]   = interval.end;
        	i++;
        }

        sort(begin(startTime), end(startTime));
        sort(begin(endTime),   end(endTime));

        i = 0;
        int j = 0;
        int count = 0;

        while(i < n) {
        	if(startTime[i] < endTime[j]) {
        		count++;
        	} else {
        		j++;
        	}
        	i++;
        }

        return count;
    }
};
