#### Key points

- We can create a mutex by constructing an instance of std::mutex, lock it with a call to the lock() member function, and unlock it with a call to the unlock() member
function. But it **isn’t recommended** practice to call the member functions directly, because this means that you have to remember to call unlock() on every code path out of a function, including those due to exceptions.
