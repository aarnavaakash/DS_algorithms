class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;

        int result = 0;

        for(int i = 0; i<n; i++) {

            for(int j = i+1; j<n; j++) {

                int count = 2;

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                for(int k = 0; k < n; k++) {

                    if(k != i && k != j) {
                        int dx_ = points[k][0] - points[i][0];
                        int dy_ = points[k][1] - points[i][1];

                        if(dx_ * dy == dy_ * dx)
                            count++;
                    }
                }

                result = max(result, count);
            }
        }

        return result;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;

        int result = 0;

        for(int i = 0; i<n; i++) {

            unordered_map<double, int> mp;

            for(int j = 0; j<n; j++) {

                if(i == j) continue;

                auto dy = points[j][1] - points[i][1];
                auto dx = points[j][0] - points[i][0];
                auto slope = atan2(dy, dx);

                mp[slope]++;

            }

            for(auto &it : mp) {
                result = max(result, it.second+1);
            }
        }

        return result;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;

        int result = 0;

        for(int i = 0; i<n; i++) {

            unordered_map<string, int> mp;

            for(int j = 0; j<n; j++) {

                if(i == j) continue;

                auto dy = points[j][1] - points[i][1];
                auto dx = points[j][0] - points[i][0];
                auto gcd = __gcd(dy, dx);

                string key = to_string(dy/gcd) + "_" + to_string(dx/gcd);

                mp[key]++;

            }

            for(auto &it : mp) {
                result = max(result, it.second+1);
            }
        }

        return result;
    }
};
