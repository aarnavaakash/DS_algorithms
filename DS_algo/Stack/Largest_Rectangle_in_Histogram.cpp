class Solution {
public:

    vector<int> NSR(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = n;
        vector<int> right(n);
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                right[i] = pseudo_index;
            } else {

                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    right[i] = pseudo_index;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }

    vector<int> NSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = -1;
        vector<int> left(n);
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                left[i] = pseudo_index;
            } else {

                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    left[i] = pseudo_index;
                else
                    left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left  = NSL(heights, n);
        vector<int> right = NSR(heights, n);

        int sum = 0;

        for(int x:left)
            cout << x << " ";
        cout << endl;
        for(int x:right)
            cout << x << " ";

        for(int i = 0; i<n; i++) {
            int area_i = heights[i]*(right[i]-left[i]-1);
            sum = max(sum, area_i);
        }

        return sum;

    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int i = 0;
        int n = heights.size();

        int maxArea = 0;
        int area    = 0;
        while(i < n) {
            if(st.empty() || heights[i] >= heights[st.top()])
                st.push(i++);
            else {
                int index = st.top();
                st.pop();
                if(st.empty()) {
                    area = heights[index] * i;
                } else {
                    area = heights[index] * (i - st.top() - 1);
                }
                maxArea = max(maxArea, area);
            }
        }

        while(!st.empty()) {
            int index = st.top();
            st.pop();

            if(st.empty()) {
                area = heights[index] * i;
            } else {
                area = heights[index] * (i - st.top() - 1);
            }
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
