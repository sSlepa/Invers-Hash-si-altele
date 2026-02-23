#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <map>
#include <cmath>
#include <chrono>
#include <set>
#include <iomanip>
#include <list>
#include <sstream>
#include <functional>
#include <numeric>
#include <string>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define INF 0x3f3f3f3f
#define MAX_LL 2000000000000000000LL
#define MOD 1000000007
#define CUSTOM_MOD 984162946217979097
#define lsb(i) (i & -i)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define triplet tuple<int,int,int>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

///__builtin_popcount(x)

/*
Problem: Implement a Thread Pool
A pool of worker threads that pick up and execute tasks from a queue.
Requirements:

ThreadPool(size_t numThreads) — spawn N worker threads
void submit(std::function<void()> task) — add a task to the queue
void shutdown() — stop accepting new tasks, finish pending ones, join all threads
Destructor should clean up properly
Thread-safe

Example:
cppThreadPool pool(4);  // 4 worker threads

pool.submit([]() {
    std::cout << "Task 1 running on thread " << std::this_thread::get_id() << "\n";
});

pool.submit([]() {
    std::cout << "Task 2 running\n";
});

// ... submit more tasks ...

pool.shutdown();  // waits for all tasks to complete
Hint:
Combine what you already know:

Bounded/unbounded queue (you built this)
Condition variables for signaling
Workers loop: wait for task → execute → repeat
*/
class ThreadPool {
public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();
    void submit(std::function<void()> task);
    void shutdown();
private:
    vector<thread> workers;
    queue<std::function<void()>> tasks;
    mutex queueMutex;
    condition_variable condition;
    bool stop;
    
    void workerThread();
};
ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back(&ThreadPool::workerThread, this);
    }
}
void ThreadPool::workerThread() {
    while (true) {
        std::function<void()> task;
        {
            unique_lock<mutex> lock(queueMutex);
            condition.wait(lock, [this] { return stop || !tasks.empty(); });
            if (stop && tasks.empty()) return;
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}
void ThreadPool::submit(std::function<void()> task) {
    {
        unique_lock<mutex> lock(queueMutex);
        if (stop) throw std::runtime_error("Submit on stopped ThreadPool");
        tasks.emplace(std::move(task));
    }
    condition.notify_one();
}
void ThreadPool::shutdown() {
    {
        unique_lock<mutex> lock(queueMutex);
        stop = true;
    }
    condition.notify_all();
    for (thread &worker : workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}
ThreadPool::~ThreadPool() {
    shutdown();
}


int main(){

    fastio
    
    ThreadPool pool(4);
    pool.submit([]() {
        std::cout << "Task 1 running on thread " << std::this_thread::get_id() << "\n";
    });
    pool.submit([]() {
        std::cout << "Task 2 running\n";
    });
    pool.shutdown(); 

    
    
    

    
    return 0;
}