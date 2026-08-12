class Solution {
public:
    typedef long long ll;

    bool isPossible(ll target, int m, vector<int>& points, int n) {
        ll moves = 0;

        ll advanceGamesToNext = 0;
        ll normalMove = 0;

        for(int i = 0; i < n && moves <= m; i++) {
            int gamePoint = points[i];

            ll games = (target + gamePoint -1) / gamePoint;

            if(advanceGamesToNext >= games) {
                advanceGamesToNext = 0;
                normalMove += 1;
            } else {
                ll pointsAlreadyCovered = advanceGamesToNext * gamePoint;

                games = (target - pointsAlreadyCovered + gamePoint - 1) / gamePoint;

                moves += (2*games) - 1;

                advanceGamesToNext = max(games-1, 0LL);

                moves += normalMove;

                normalMove = 0;
            }
        }

        return moves <= m;
    }

    long long maxScore(vector<int>& points, int m) {
        int n = points.size();

        ll l = 1;
        ll r = 1e15;

        ll result = 0;

        while(l <= r) {
            ll mid = l + (r-l)/2;

            if(isPossible(mid, m, points, n) == true) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;
    }
};
