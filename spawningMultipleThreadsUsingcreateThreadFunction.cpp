#include <iostream>
#include <string>
#include <thread>
#include <vector>
using namespace std;
void getAverage(int i, int j) {
  int sum = 0;
  int count = 0;
  for (int k = i; k <= j; k++) {
    sum += k;
    count++;
  }
  cout << "Thread Calculated avg of range " << i << "," << j << " is "
       << double(sum) / double(count) << "\n";
}
thread createNewThread(int i, int j) {
  thread t(getAverage, i, j);
  return t;
}

int main() {
  int upperLimit = 100;
  vector<thread> v;
  for (int i = 0; i < upperLimit; i += 10) {
    v.push_back(createNewThread(i, i + 10));
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i].joinable()) {
      v[i].join();
    }
  }
}
