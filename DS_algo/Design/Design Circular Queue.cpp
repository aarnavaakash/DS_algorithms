class MyCircularDeque {
public:
    vector<int> deq;
    int K;
    int front;
    int rear;
    int currentCount;

    MyCircularDeque(int k) {
        K = k;
        deq = vector<int>(K, 0);
        front = 0;
        rear  = K-1;
        currentCount = 0;
    }

    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }

        front = (front - 1 + K) % K;
        deq[front] = value;
        currentCount++;
        return true;
    }

    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }

        rear = (rear + 1) % K;
        deq[rear] = value;
        currentCount++;
        return true;
    }

    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        front = (front + 1) % K;
        currentCount--;
        return true;
    }

    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }

        rear = (rear - 1 + K) % K;
        currentCount--;
        return true;
    }

    int getFront() {
        if(isEmpty()) {
            return -1;
        }

        return deq[front];
    }

    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return deq[rear];
    }

    bool isEmpty() {
        return currentCount == 0;
    }

    bool isFull() {
        return currentCount == K;
    }
};

class MyCircularDeque {
private:
    list<int> deq;
    int cnt;
    int k;
public:

    MyCircularDeque(int k) {
        this->k = k;
        cnt = 0;
    }

    bool insertFront(int value) {
        if (cnt == k) {
            return false;
        }
        deq.push_front(value);
        ++cnt;
        return true;
    }

    bool insertLast(int value) {
        if (cnt == k) {
            return false;
        }
        deq.push_back(value);
        ++cnt;
        return true;
    }

    bool deleteFront() {
        if (cnt == 0) {
            return false;
        }
        deq.pop_front();
        --cnt;
        return true;
    }

    bool deleteLast() {
        if (cnt == 0) {
            return false;
        }
        deq.pop_back();
        --cnt;
        return true;
    }

    int getFront() {
        if (cnt == 0) {
            return -1;
        }
        return deq.front();
    }

    int getRear() {
        if (cnt == 0) {
            return -1;
        }
        return deq.back();
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == k;
    }
};
