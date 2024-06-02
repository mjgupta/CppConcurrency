#include <condition_variable>
#include <mutex>
using namespace std;
class Foo {
  mutex _mu;
  int cnt;
  condition_variable _cond;

public:
  Foo() { cnt = 3; }

  void first(function<void()> printFirst) {
    unique_lock<mutex> l(_mu);
    _cond.wait(l, [this] { return cnt == 3; });
    printFirst();
    cnt = 1;
    _cond.notify_all();
  }

  void second(function<void()> printSecond) {

    // printSecond() outputs "second". Do not change or remove this line.
    unique_lock<mutex> l(_mu);
    _cond.wait(l, [this] { return cnt == 1; });
    printSecond();
    cnt = 2;
    _cond.notify_all();
  }

  void third(function<void()> printThird) {
    // printThird() outputs "third". Do not change or remove this line.
    unique_lock<mutex> l(_mu);
    _cond.wait(l, [this] { return cnt == 2; });
    printThird();
    cnt = 3;
    _cond.notify_all();
  }
};
