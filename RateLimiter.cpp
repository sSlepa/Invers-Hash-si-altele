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
Problem: Token Bucket Rate Limiter
Implement a rate limiter that controls how many requests can pass through in a given time window.
Requirements:

RateLimiter(int maxTokens, double refillRate) — max capacity and tokens added per second
bool allowRequest() — returns true if request is allowed, false if rate limited
Tokens accumulate over time up to maxTokens
Each allowed request consumes one token
Thread-safe

RateLimiter limiter(10, 2.0);  // max 10 tokens, refill 2 per second

limiter.allowRequest();  // true, 9 tokens left
limiter.allowRequest();  // true, 8 tokens left
// ... 8 more requests ...
limiter.allowRequest();  // false, 0 tokens

// wait 1 second... now 2 tokens have refilled

limiter.allowRequest();  // true
limiter.allowRequest();  // true
limiter.allowRequest();  // false
*/

class RateLimiter {
private:
    int maxTokens;
    double refillRate; // tokens per second
    double currentTokens;
    steady_clock::time_point lastRefillTime;
    mutex mtx;

    void refill() {
        auto now = steady_clock::now();
        double secondsPassed = duration<double>(now - lastRefillTime).count();
        double tokensToAdd = secondsPassed * refillRate;
        currentTokens = min(static_cast<double>(maxTokens), currentTokens + tokensToAdd);
        lastRefillTime = now;
    }
public:
    RateLimiter(int maxTokens, double refillRate)
        : maxTokens(maxTokens), refillRate(refillRate), currentTokens(maxTokens),
          lastRefillTime(steady_clock::now()) {}

    bool allowRequest() {
        lock_guard<mutex> lock(mtx);
        refill();
        if (currentTokens >= 1.0) {
            currentTokens -= 1.0;
            return true;
        }
        return false;
    }

};

int main(){

    fastio
    RateLimiter limiter(10, 2.0);  // max 10 tokens, refill 2 per second
    for (int i = 0; i < 12; ++i) {
        cout << "Request " << i + 1 << ": " << (limiter.allowRequest() ? "Allowed" : "Rate Limited") << endl;
    }
    cout << endl;

    // Simulate waiting for 1 second
    this_thread::sleep_for(chrono::seconds(1));
    for (int i = 0; i < 5; ++i) {
        cout << "Request after wait " << i + 1 << ": " << (limiter.allowRequest() ? "Allowed" : "Rate Limited") << endl;
    }
    cout << endl;
    // Simulate waiting for another 2 seconds
    this_thread::sleep_for(chrono::seconds(2));
    for (int i = 0; i < 5; ++i) {
        cout << "Request after second wait " << i + 1 << ": " << (limiter.allowRequest() ? "Allowed" : "Rate Limited") << endl;
    }

    
    
    

    
    return 0;
}
