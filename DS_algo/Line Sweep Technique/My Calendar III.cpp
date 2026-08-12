class Solution {
class MyCalendarThree {
public:
    map<int, int> events;
    MyCalendarThree() {

    }

    int book(int startTime, int endTime) {
        events[startTime] += 1;
        events[endTime] -= 1;

        int count = 0;
        int maxInt = 0;
        for(auto &it : events) {
            count += it.second;
            maxInt = max(maxInt, count);
        }

        return maxInt;
    }
};
