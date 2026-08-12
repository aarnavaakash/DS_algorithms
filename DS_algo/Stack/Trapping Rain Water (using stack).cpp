class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water = 0;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && height[i] > height[st.top()]) {

                int mid = st.top();
                st.pop();

                if(st.empty()) {
                    break;
                }

                int right = i;
                int left  = st.top();

                int h = min(height[right], height[left]) - height[mid];
                int w = right - left - 1;

                water += (h*w);
            }
            st.push(i);
        }

        return water;
    }
};
