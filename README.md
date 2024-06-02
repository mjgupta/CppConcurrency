#### Key points

- We can create a mutex by constructing an instance of std::mutex, lock it with a call to the lock() member function, and unlock it with a call to the unlock() member
function. But it **isn’t recommended** practice to call the member functions directly, because this means that you have to remember to call unlock() on every code path out of a function, including those due to exceptions.
- C++ Library provides the **std::lock_guard** class template, which implements that RAII idiom for a mutex; it locks the supplied mutex on construction and unlocks it on destruction, ensuring a locked mutex is always correctly unlocked. 
