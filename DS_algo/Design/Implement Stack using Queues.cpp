class MyStack {
public:

    queue<int> q1;
    queue<int> q2;
    MyStack() {

    }

    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());    q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int result = top();
        q1.pop();
        return result;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

class MyStack {
public:
    queue<int> que;

    MyStack() {
    }

    void push(int x) {
        que.push(x);
        for(int i = 0; i<que.size()-1; i++) {
            que.push(que.front());
            que.pop();
        }
    }

    int pop() {
        int x = que.front();
        que.pop();
        return x;
    }

    int top() {
        return que.front();
    }

    bool empty() {
        return que.empty();
    }
};

class MyStack {
public:
    deque<int> deq;

    MyStack() {
        deq.clear();
    }

    void push(int x) {
        return deq.push_back(x);
    }

    int pop() {
        int top = deq.back();
        deq.pop_back();
        return top;
    }

    int top() {
        return deq.back();
    }

    bool empty() {
        return deq.empty();
    }
};
