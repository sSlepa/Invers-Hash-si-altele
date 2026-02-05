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
Sliding Window Counter
Count events within a time window (e.g., requests in last 60 seconds).
Requirements:

SlidingWindowCounter(int windowSizeSeconds) — set the window
void recordEvent() — record an event at current time
int getCount() — return number of events in the last windowSizeSeconds
*/
class SlidingWindowCounter {
private:
    int windowSize;
    queue<pair<long long, int>> events; // pair<timestamp, count>
    int currentCount;

    long long getCurrentTime() {
        return duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
    }

    void evictOldEvents() {
        long long currentTime = getCurrentTime();
        while (!events.empty() && events.front().first <= currentTime - windowSize) {
            currentCount -= events.front().second;
            events.pop();
        }
    }
public:
    SlidingWindowCounter(int windowSizeSeconds) : windowSize(windowSizeSeconds), currentCount(0) {}

    void recordEvent() {
        long long currentTime = getCurrentTime();
        if (!events.empty() && events.back().first == currentTime) {
            events.back().second++;
        } 
        else {
            events.push({currentTime, 1});
        }
        currentCount++;
        evictOldEvents();
    }

    int getCount() {
        evictOldEvents();
        return currentCount;
    }
};



int main(){

    fastio
    SlidingWindowCounter counter(60); // 60 seconds window
    counter.recordEvent();
    counter.recordEvent();
    cout << "Events in last 60 seconds: " << counter.getCount() << endl;

    // Simulate waiting for some time

    this_thread::sleep_for(chrono::seconds(61));
    cout << "Events in last 60 seconds after 61 seconds: " << counter.getCount() << endl;

    // Simulate more events
    counter.recordEvent();
    cout << "Events in last 60 seconds after recording another event: " << counter.getCount() << endl;

    

    
    return 0;
}
