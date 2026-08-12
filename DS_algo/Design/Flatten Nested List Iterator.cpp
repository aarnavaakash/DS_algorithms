class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = n-1; i>=0; i--)
            st.push(nestedList[i]);
    }

    int next() {

        int num =  st.top().getInteger();
        st.pop();
        return num;
    }

    bool hasNext() {

        while(!st.empty()) {
            NestedInteger curr = st.top();
            if(curr.isInteger())
                return true;

            st.pop();
            vector<NestedInteger>& vec = curr.getList();
            for(int i = vec.size()-1; i>=0; i--)
                st.push(vec[i]);
        }
        return false;
    }
};

class NestedIterator {
public:
    stack<NestedInteger*> st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = n-1; i>=0; i--)
            st.push(&nestedList[i]);
    }

    int next() {

        int num =  st.top()->getInteger();
        st.pop();
        return num;
    }

    bool hasNext() {

        while(!st.empty()) {
            NestedInteger* curr = st.top();
            if(curr->isInteger())
                return true;

            st.pop();
            vector<NestedInteger>& vec = curr->getList();
            for(int i = vec.size()-1; i>=0; i--)
                st.push(&vec[i]);
        }
        return false;
    }
};

class NestedIterator {
public:
    queue<int> que;
    NestedIterator(vector<NestedInteger> &nestedList) {
        addAll(nestedList);
    }

    void addAll(vector<NestedInteger>& nestedList) {
        int n = nestedList.size();
        for(int i = 0; i<n; i++) {
            NestedInteger& obj = nestedList[i];
            if(obj.isInteger())
                que.push(obj.getInteger());
            else {
                addAll(obj.getList());
            }
        }
    }

    int next() {
        int num = que.front();
        que.pop();
        return num;
    }

    bool hasNext() {
        return !que.empty();
    }
};
