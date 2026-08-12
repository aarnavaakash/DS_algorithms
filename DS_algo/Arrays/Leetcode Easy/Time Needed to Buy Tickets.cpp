class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> que;

        for (int i = 0; i < n; i++) {
            que.push(i);
        }

        int time = 0;

        while (!que.empty()) {
            time++;
            int front = que.front();
            que.pop();

            tickets[front]--;

            if (k == front && tickets[front] == 0) {
                return time;
            }
            if (tickets[front] != 0) {
                que.push(front);
            }
        }

        return time;
    }
};

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;

        if (tickets[k] == 1)
            return k + 1;

        while (tickets[k] > 0) {
            for (int i = 0; i < n; i++) {

                if (tickets[i] != 0) {
                    tickets[i]--;
                    time++;
                }

                if (tickets[k] == 0)
                    return time;
            }
        }

        return time;
    }
};

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        for (int i = 0; i < tickets.size(); i++) {

            if (i <= k) {
                time += min(tickets[k], tickets[i]);
            } else {
                time += min(tickets[k] - 1, tickets[i]);
            }
        }

        return time;
    }
};
