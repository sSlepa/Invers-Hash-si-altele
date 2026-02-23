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
Task 7: Ring Buffer
A fixed-size circular buffer for streaming data. When full, oldest data is overwritten.
Requirements:

RingBuffer(size_t capacity) — fixed size
void push(T item) — add item, overwrite oldest if full
std::optional<T> pop() — remove and return oldest item, or nullopt if empty
size_t size() — current number of items
bool empty() / bool full()
Thread-safe
*/
template<typename T>
class RingBuffer {
private:
    vector<T> buffer;
    size_t head;
    size_t tail;
    size_t capacity;
    size_t current_size;
    mutex mtx;
    bool _empty() const { return current_size == 0; }
    bool _full() const { return current_size == capacity; }

public:
    void push(T item) {
        lock_guard<mutex> lock(mtx);
        buffer[tail] = item;
        if (_full()) {
            head = (head + 1) % capacity;
        } else {
            current_size++;
        }
        tail = (tail + 1) % capacity;
    }

    optional<T> pop() {
        lock_guard<mutex> lock(mtx);
        if (_empty()) return nullopt;
        T item = buffer[head];
        head = (head + 1) % capacity;
        current_size--;
        return item;
        
    }

    bool empty() {
        lock_guard<mutex> lock(mtx);
        return _empty();
    }

    bool full() {
        lock_guard<mutex> lock(mtx);
        return _full();
    }
};

int main(){

    fastio
    
    
    

    
    return 0;
}
