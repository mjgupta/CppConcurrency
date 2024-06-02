#include <iostream>
#include <string>
#include <thread>
using namespace std;
class C {
  string name;

public:
  C(string s_) { name = s_; }
  void prnt() {
    for (int i = 0; i < 10; i++)
      cout << name << "\n";
  }
};

int main() {
  // int x = 3;
  C instance1 = C("Raghu");
  C instance2 = C("To");
  thread t1(&C::prnt, &instance1);
  thread t2(&C::prnt, ref(instance2));
  // cout << "Hello from Main Thread " << s << "\n";
  t1.join();
  t2.join();
}
