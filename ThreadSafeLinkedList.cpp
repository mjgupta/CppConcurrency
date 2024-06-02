#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
mutex mu;
list<int> l;
void addToEnd(int val) {
  lock_guard<mutex> guard(mu);
  l.push_back(val); }
void removeFromEnd() {
  lock_guard<mutex> guard(mu);
  if (!l.empty()) {
    int val = l.back();
    l.pop_back();
    cout << val << ",";
  } else
    cout << "E ";
}

int main() {
  vector<thread> v;
  for (int i = 1; i <= 1000; i++) {
    // thread t1(addToEnd, i);
    // thread t2(removeFromEnd);
    v.push_back(thread(addToEnd, i));
    v.push_back(thread(removeFromEnd));
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i].joinable())
      v[i].join();
  }
}
