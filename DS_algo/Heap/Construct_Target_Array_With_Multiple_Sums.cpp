class Solution {
    typedef long long ll;
public:
    bool isPossible(vector<int>& target) {
        int n       = target.size();

        priority_queue<ll> pq;
        ll sum = 0;
        for(int x:target) {
            pq.push(x);
            sum += x;
        }

        while(!pq.empty()) {
            ll biggest_before = pq.top();
            pq.pop();

            if(biggest_before == 1)
                return true;

            ll remain_sum = sum - biggest_before;
            if(remain_sum >= biggest_before)
                return false;
            if(remain_sum == 1)
                return true;
            if(remain_sum == 0)
                return false;

            ll biggest_after = biggest_before % remain_sum;
            if(biggest_after < 1)
                return false;

            sum = remain_sum + biggest_after;

            pq.push(biggest_after);
        }

        return true;
    }
};
