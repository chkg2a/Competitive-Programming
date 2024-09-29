#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
private:
    vector<int> queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        queue = vector<int>(k);
        size = 0;
        capacity = k;
        front = 0;
        rear = k - 1;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        queue[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return queue[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return queue[rear];
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
}; 

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  MyCircularDeque* obj = new MyCircularDeque(3);
  obj->insertFront(1);
  obj->insertLast(2);
  obj->insertFront(3);
  obj->insertLast(4);
  obj->getFront();
  obj->getRear();
  obj->insertFront(4);
  obj->insertLast(5);
  obj->getFront();
  obj->getRear();
  obj->deleteFront();
  obj->deleteLast();
  obj->getFront();
  obj->getRear();

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds " << std::endl;
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds " << std::endl;
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
