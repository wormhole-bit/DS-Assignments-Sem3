class PriorityQueue {
    int a[100];
    int n;

public:
    PriorityQueue() { n = 0; }

    void push(int x) {
        int i = n++;
        a[i] = x;

        while (i > 0 && a[(i-1)/2] < a[i]) {
            swap(a[i], a[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int pop() {
        if (n == 0) return -1;
        int top = a[0];
        a[0] = a[--n];
        heapify(a, n, 0);
        return top;
    }

    bool empty() { return n == 0; }
};
