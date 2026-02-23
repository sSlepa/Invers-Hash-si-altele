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
#include <atomic>
#include <optional>

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
🎲 Task 13: Lock-Free Stack (Compare-And-Swap)
Implement a thread-safe stack using std::atomic — no mutexes.
Requirements:

void push(T value)
std::optional<T> pop()
Uses a singly linked list internally
Thread safety via compare_exchange_weak
*/

template<typename T>
class LockFreeStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    atomic<Node*> head;

public:
    LockFreeStack() : head(nullptr) {}

    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = head.load();
        while (!head.compare_exchange_weak(newNode->next, newNode));
    }

    optional<T> pop() {
        Node* oldHead = head.load();

        while (oldHead && !head.compare_exchange_weak(oldHead, oldHead->next));
        
        if (!oldHead) 
            return nullopt;

        T value = oldHead->data;
        delete oldHead;
        return value;
    }

    ~LockFreeStack() {
        while (pop().has_value());
    }
};

int main(){

    fastio

    LockFreeStack<int> stack;

    // Spawn threads that push concurrently
    vector<thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.emplace_back([&stack, i]() {
            for (int j = 0; j < 5; j++) {
                stack.push(i * 10 + j);
            }
        });
    }
    for (auto& t : threads) t.join();

    // Pop all elements
    optional<int> val;
    while ((val = stack.pop()).has_value()) {
        cout << val.value() << " ";
    }
    cout << endl;

    return 0;
}
