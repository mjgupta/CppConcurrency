#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;
class BoundedBlockingQueue {
  queue<int> q;
  int maxSize;
  mutex _mu;
  condition_variable _cond;

public:
  BoundedBlockingQueue(int capacity) {
    lock_guard<mutex> l(_mu);
    maxSize = capacity;
  }

  void enqueue(int element) {
    unique_lock<mutex> l(_mu);
    _cond.wait(l, [this] { return (q.size() < maxSize); });
    q.push(element);
    _cond.notify_one();
  }

  int dequeue() {
    unique_lock<mutex> l(_mu);
    _cond.wait(l, [this] { return !(q.empty()); });
    int ret = q.front();
    q.pop();
    _cond.notify_one();
    return ret;
  }

  int size() {
    lock_guard<mutex> l(_mu);
    return q.size();
  }
};

/*
  Testing locally , Not for leetcode 
*/
void producer(BoundedBlockingQueue &q, int maxVal) {
  for (int i = 1; i <= maxVal; i++) {
    q.enqueue(i);
    printf(" Pushed %d \n", i);
  }
}
void consumer(BoundedBlockingQueue &q, int maxVal) {
  for (int i = 1; i <= maxVal; i++) {
    int val = q.dequeue();
    printf(" Popped %d \n", val);
  }
}
int main() {
  BoundedBlockingQueue q(20);
  thread p(producer, ref(q), 200);
  thread c(consumer, ref(q), 200);
  p.join();
  c.join();
}
