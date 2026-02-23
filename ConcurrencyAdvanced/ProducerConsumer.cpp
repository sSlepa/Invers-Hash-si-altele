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

template <typename T>
class BoundingQueue {
private:
    std::queue<T> q;
    size_t capacity;
    std::mutex mtx;
    std::condition_variable not_empty; 
    std::condition_variable not_full;   

public:
    BoundingQueue(size_t capacity) : capacity(capacity) {}

    void enqueue(const T& item) {
        std::unique_lock<std::mutex> lock(mtx);
        not_full.wait(lock, [this]() { return q.size() < capacity; });
        q.push(item);
        not_empty.notify_one();
    }
    T dequeue() {
        std::unique_lock<std::mutex> lock(mtx);
        not_empty.wait(lock, [this]() { return !q.empty(); });
        T item = q.front();
        q.pop();
        not_full.notify_one();
        return item;
    }
    
    size_t size() {
        std::lock_guard<std::mutex> lock(mtx);
        return q.size();
    }

    bool empty() {
        std::lock_guard<std::mutex> lock(mtx);
        return q.empty();
    }

    bool full() {
        std::lock_guard<std::mutex> lock(mtx);
        return q.size() >= capacity;
    }
};

int main(){

    fastio

    
    
    

    
    return 0;
}
