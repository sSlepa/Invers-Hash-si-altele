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
Problem: Implement a Read-Write Lock
A synchronization primitive that allows concurrent reads but exclusive writes.
Requirements:

void lockRead() — acquire read lock (blocks if writer is active)
void unlockRead() — release read lock
void lockWrite() — acquire write lock (blocks if any readers or writer active)
void unlockWrite() — release write lock
Multiple readers can hold the lock simultaneously
Only one writer can hold the lock, and no readers while writing
Prevent writer starvation — if a writer is waiting, new readers should wait
*/
class ReadWriteLock {
private:
    mutex mtx;
    condition_variable readersCond;
    condition_variable writersCond;
    int activeReaders;
    int waitingWriters;
    bool writerActive;
public:
    ReadWriteLock() : activeReaders(0), waitingWriters(0), writerActive
(false) {}
    void lockRead() {
        unique_lock<mutex> lock(mtx);
        readersCond.wait(lock, [this]() { return waitingWriters == 0 && !writerActive; });
        ++activeReaders;
    }
    void unlockRead() {
        unique_lock<mutex> lock(mtx);
        --activeReaders;
        if (activeReaders == 0 && waitingWriters > 0) {
            writersCond.notify_one();
        }
    }
    void lockWrite() {
        unique_lock<mutex> lock(mtx);
        ++waitingWriters;
        writersCond.wait(lock, [this]() { return activeReaders == 0 && !writerActive; });
        --waitingWriters;
        writerActive = true;
    }
    void unlockWrite() {
        unique_lock<mutex> lock(mtx);
        writerActive = false;
        if (waitingWriters > 0) {
            writersCond.notify_one();
        } else {
            readersCond.notify_all();
        }
    }
};


int main(){

    fastio

    ReadWriteLock rwLock;
    
    rwLock.lockRead();
    cout << "Read lock acquired\n";
    rwLock.unlockRead();
    cout << "Read lock released\n";
    rwLock.lockWrite();
    cout << "Write lock acquired\n";
    rwLock.unlockWrite();
    cout << "Write lock released\n";
    
    

    
    return 0;
}
