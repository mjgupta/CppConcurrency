/*
  A function that returns while a thread still has access to local variables
*/
#include <iostream>
#include <thread>
using namespace std;
void prnt(int &x) 
{
  for(int i=0;i<30000;i++) std::cout << "Hello from Child Thread!" << x << "\n"; 
}
int main() {
  int x = 3;
  thread t(prnt, ref(x));
  cout << "Hello from Main Thread \n";
  t.detach();
}
