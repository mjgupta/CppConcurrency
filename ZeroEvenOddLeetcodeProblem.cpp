#include <bits/stdc++.h>
using namespace std;
class ZeroEvenOdd {
private:
  int n;
  mutex _mu;
  condition_variable _cond;
  int cnt;
  int x;
  void printNumber(int x) { printf("%d,", x); }

public:
  ZeroEvenOdd(int n) {
    this->n = n;
    cnt = 1;
    x = 0;
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero() {
    while (cnt <= 2 * n) {
      unique_lock<mutex> l(_mu);
      _cond.wait(l, [this] { return (cnt % 2 == 1) || (cnt > 2 * n); });
      if (cnt > 2 * n)
        return;
      // cout<<"#"<<x<<" , "<<cnt<<" # \n";
      printNumber(0);
      x++;
      cnt++;
      _cond.notify_all();
    }
  }

  void even() {
    while (cnt <= 2 * n) {
      unique_lock<mutex> l(_mu);
      _cond.wait(l, [this] { return (cnt % 4 == 0) || (cnt > 2 * n); });
      if (cnt > 2 * n)
        return;
      printNumber(x);
      cnt++;
      _cond.notify_all();
    }
  }

  void odd() {
    while (cnt <= 2 * n) {
      unique_lock<mutex> l(_mu);
      _cond.wait(l, [this] { return (cnt % 4 == 2) || (cnt > 2 * n); });
      if (cnt > 2 * n)
        return;
      printNumber(x);
      cnt++;
      _cond.notify_all();
    }
  }
};

int main() {
  ZeroEvenOdd z(1);
  thread t1(&ZeroEvenOdd::zero, ref(z));
  thread t2(&ZeroEvenOdd::odd, ref(z));
  thread t3(&ZeroEvenOdd::even, ref(z));
  t1.join();
  t2.join();
  t3.join();
}
