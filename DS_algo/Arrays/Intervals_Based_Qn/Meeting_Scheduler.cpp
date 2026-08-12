class Solution {
public:
     vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {

          sort(slots1.begin(), slots1.end());
          sort(slots2.begin(), slots2.end());

          int m = slots1.size();
          int n = slots2.size();
          int i = 0, j = 0;

          while(i < m && j < n) {

              int start = max(slots1[i][0], slots2[j][0]);
              int end   = min(slots1[i][1], slots2[j][1]);

              if(end-start >= duration) {
                  return {start, start+duration};
              } else {
                   if(slots1[i][1] == end)
                        i++;
                   if(slots2[j][1] == end)
                        j++;
              }
          }

          return {};
     }
};
