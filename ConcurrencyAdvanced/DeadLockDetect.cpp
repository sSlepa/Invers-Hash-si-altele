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
**Task 8: Deadlock Detector**

Given a set of resource acquisition events, detect if a circular wait (deadlock) exists.

**Input:**
- A list of events: `(thread_id, action, resource_id)`
- Actions: `LOCK` or `WAIT`
- `LOCK` means thread holds the resource
- `WAIT` means thread is waiting for the resource

**Requirements:**
- `void addLock(int threadId, int resourceId)` — thread acquired resource
- `void addWait(int threadId, int resourceId)` — thread is waiting for resource
- `bool hasDeadlock()` — return true if circular wait exists
- `void releaseLock(int threadId, int resourceId)` — thread released resource

Hint:
Build a directed graph: thread → resource it waits for → thread that holds it. Detect cycles using DFS.
*/

class DeadlockDetector {
private:
    unordered_map<int, unordered_set<int>> waitGraph; // thread -> resources it waits for
    unordered_map<int, int> resourceHolder; // resource -> thread holding it

    bool dfs(int threadId, unordered_set<int>& visited, unordered_set<int>& recStack) {

        if (recStack.find(threadId) != recStack.end()) 
            return true;

        if (visited.find(threadId) != visited.end()) 
            return false;

        visited.insert(threadId);
        recStack.insert(threadId);

        for (int resourceId : waitGraph[threadId]) {
            if (resourceHolder.find(resourceId) != resourceHolder.end()) {
                int holdingThread = resourceHolder[resourceId];
                if (dfs(holdingThread, visited, recStack)) 
                    return true;
            }
        }

        recStack.erase(threadId);
        return false;
    }
public:
    void addLock(int threadId, int resourceId) {
        resourceHolder[resourceId] = threadId;
        waitGraph[threadId].erase(resourceId);
    }

    void addWait(int threadId, int resourceId) {
        waitGraph[threadId].insert(resourceId);
    }

    bool hasDeadlock() {
        unordered_set<int> visited;
        unordered_set<int> recStack;

        for (const auto& pair : waitGraph) {
            int threadId = pair.first;
            if (dfs(threadId, visited, recStack)) {
                return true;
            }
        }
        return false;
    }

    void releaseLock(int threadId, int resourceId) {
        if (resourceHolder.find(resourceId) != resourceHolder.end() && resourceHolder[resourceId] == threadId) {
            resourceHolder.erase(resourceId);
        }
    }
};

int main(){

    fastio
    DeadlockDetector detector;
    detector.addLock(1, 101);
    detector.addWait(2, 101);
    detector.addLock(2, 102);
    detector.addWait(1, 102);
    if (detector.hasDeadlock()) {
        cout << "Deadlock detected!" << endl;
    } else {
        cout << "No deadlock." << endl;
    }
    // another test case
    DeadlockDetector detector2;
    detector2.addLock(1, 201);
    detector2.addWait(2, 201);
    detector2.addLock(2, 202);
    detector2.addWait(3, 202);
    if (detector2.hasDeadlock()) {
        cout << "Deadlock detected!" << endl;
    } else {
        cout << "No deadlock." << endl;
    }

    
    

    
    return 0;
}
