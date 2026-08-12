class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> result(n, 0);

        bool skip = false;

        int i = 0;
        int j = 0;

        sort(begin(deck), end(deck));

        while(i < n) {

            if(result[j] == 0) {

                if(skip == false) {
                    result[j] = deck[i];
                    i++;
                }

                skip = !skip;

            }

            j = (j+1)%n;

        }

        return result;
    }
};

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        queue<int> que;
        vector<int> result(n);

        for(int i = 0; i < n; i++) {
            que.push(i);
        }

        sort(begin(deck), end(deck));

        for(int i = 0; i < n; i++) {

            int idx = que.front();
            que.pop();

            result[idx] = deck[i];

            if(!que.empty()) {
                que.push(que.front());
                que.pop();
            }

        }

        return result;
    }
};
