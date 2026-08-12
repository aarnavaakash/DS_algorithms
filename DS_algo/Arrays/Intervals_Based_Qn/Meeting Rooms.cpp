class Solution {
public:
     static bool myFunction(Interval& i1, Interval& i2) {
        return i1.start < i2.start;

     }
    bool canAttendMeetings(vector<Interval> &intervals) {
        if(intervals.size() == 0)
            return true;
        sort(intervals.begin(), intervals.end(), myFunction);

        Interval prevInterval = intervals[0];
        for(int i = 1; i<intervals.size(); i++) {
            int currInterval_start = intervals[i].start;
            if(currInterval_start < prevInterval.end) {
                return false;
            } else {
                prevInterval = intervals[i];
            }
        }
        return true;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval> &intervals) {
        auto lambda = [&](Interval& i1, Interval& i2) {
            return i1.start < i2.start;
        };

        sort(begin(intervals), end(intervals), lambda);
        int n = intervals.size();

        for(int i = 0; i<n-1; i++) {
            Interval curr  = intervals[i];
            Interval next  = intervals[i+1];

            if(curr.end <= next.start) {
                continue;
            }

            if(curr.end > next.start) {
                return false;
            }
        }
        return true;

    }
};
