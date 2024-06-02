#### Key points

- We can create a mutex by constructing an instance of std::mutex, lock it with a call to the lock() member function, and unlock it with a call to the unlock() member
function. But it **isn’t recommended** practice to call the member functions directly, because this means that you have to remember to call unlock() on every code path out of a function, including those due to exceptions.
- C++ Library provides the **std::lock_guard** class template, which implements that RAII idiom for a mutex; it locks the supplied mutex on construction and unlocks it on destruction, ensuring a locked mutex is always correctly unlocked.
-  The common advice for avoiding deadlock is to always lock the two mutexes in the same order: if you always lock mutex A before mutex B, then you’ll never deadlock. **std::lock** —a function that can lock two or more mutexes at once without risk of
deadlock. std::lock provides all-or-nothing semantics with regard to locking the supplied mutexes.
- If you absolutely must acquire two or more locks, and you can’t acquire them as a single operation with std::lock, the next best thing is to acquire them in the same order in every thread.
- C++ 11 onwards, initialization of a static variable is thread safe in nature, not the case before C++11 , where there might be race conditions.
