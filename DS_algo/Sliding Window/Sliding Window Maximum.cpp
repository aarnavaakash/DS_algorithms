****************************************** C++ ******************************************************

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)
            return {};
        deque<int> deq;

        vector<int> result;

        for(int i = 0; i<n; i++) {

            while(!deq.empty() && deq.front() <= i-k)
                deq.pop_front();

            while(!deq.empty() && nums[i] > nums[deq.back()])
                deq.pop_back();

            deq.push_back(i);

            if(i >= k-1)
                result.push_back(nums[deq.front()]);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> result;

        int n = nums.size();

        for(int i = 0; i<n; i++) {

            while(!pq.empty() && pq.top().second <= i-k)
                pq.pop();

            pq.push({nums[i], i});

            if(i >= k-1)
                result.push_back(pq.top().first);
        }
        return result;
    }
};

****************************************** JAVA ******************************************************

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        int i=0, j=0, ptr=0;
        int n = nums.length;
        int[] res = new int[n-k+1];

        while(j<n){
            while(!q.isEmpty() && q.peekLast()<nums[j]){
                q.pollLast();
            }

            q.add(nums[j]);

            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){

                res[ptr++] = q.peek();

                if(nums[i]==q.peek()){
                    q.pollFirst();
                }
                i++;
                j++;
            }
        }

        return res;

    }
}
