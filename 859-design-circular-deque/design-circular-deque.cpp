class MyCircularDeque {
public:
    vector<int> dq;
    int front, rear, cnt, k;

    MyCircularDeque(int k) {
        this->k = k;
        dq.resize(k);
        front = 0;
        rear = 0;
        cnt = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        front = (front - 1 + k) % k;
        dq[front] = value;
        cnt++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        dq[rear] = value;
        rear = (rear + 1) % k;
        cnt++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        front = (front + 1) % k;
        cnt--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        rear = (rear - 1 + k) % k;
        cnt--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return dq[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return dq[(rear - 1 + k) % k];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == k;
    }
};