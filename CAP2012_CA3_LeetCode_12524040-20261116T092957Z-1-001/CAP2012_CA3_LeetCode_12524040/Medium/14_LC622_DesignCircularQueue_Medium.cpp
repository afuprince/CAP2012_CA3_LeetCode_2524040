// LeetCode 622 - Design Circular Queue (Medium)
// Topics: Circular queue, FRONT, REAR, enqueue/dequeue | Unit IV
// Approach: Fixed-size array with head index and element count; indices wrap using modulo.
// All operations O(1).
#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    vector<int> data;
    int head, count, capacity;

public:
    MyCircularQueue(int k) : data(k), head(0), count(0), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        data[(head + count) % capacity] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        count--;
        return true;
    }

    int Front() { return isEmpty() ? -1 : data[head]; }

    int Rear() { return isEmpty() ? -1 : data[(head + count - 1) % capacity]; }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == capacity; }
};

int main() {
    cout << boolalpha;
    MyCircularQueue q(3);
    cout << q.enQueue(1) << "\n"; // true
    cout << q.enQueue(2) << "\n"; // true
    cout << q.enQueue(3) << "\n"; // true
    cout << q.enQueue(4) << "\n"; // false (full)
    cout << q.Rear() << "\n";     // 3
    cout << q.isFull() << "\n";   // true
    cout << q.deQueue() << "\n";  // true
    cout << q.enQueue(4) << "\n"; // true
    cout << q.Rear() << "\n";     // 4
    cout << q.Front() << "\n";    // 2
    return 0;
}
