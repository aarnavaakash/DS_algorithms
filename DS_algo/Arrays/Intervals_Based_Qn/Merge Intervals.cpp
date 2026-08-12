class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0;
        while(i < intervals.size()-1) {
            int i_start = intervals[i][0];
            int i_end  = intervals[i][1];
            bool merge = false;
            for(int j = i+1; j<intervals.size(); j++) {

                int j_start = intervals[j][0];
                int j_end  = intervals[j][1];

                if(!(i_end < j_start || i_start > j_end)) {

                    intervals[i][0] = min(i_start, j_start);
                    intervals[i][1] = max(i_end, j_end);

                    intervals.erase(intervals.begin()+j);
                    merge = true;
                    break;
                }

            }
            if(!merge) {
                i++;
            }
        }
        return intervals;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++) {

            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            if(curr_start > result.back()[1]) {
                result.push_back(intervals[i]);
            } else {

                result.back()[1] = max(result.back()[1], curr_end);
            }

        }

        return result;

    }
};
