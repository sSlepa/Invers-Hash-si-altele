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

template<typename T1, typename T2>
class LRUCache {
    private:
        unordered_map<T1, typename list<pair<T1,T2>>::iterator> cache;
        list<pair<T1,T2>> usage;
        int capacity;
        std::mutex mtx;
    public:
        LRUCache(int capacity) : capacity(capacity) {}

        std::optional<T2> get(T1 key) {
            std::lock_guard<std::mutex> lock(mtx);
            auto it = cache.find(key);
            if (it == cache.end()) {
                return std::nullopt;
            }
            usage.splice(usage.begin(), usage, it->second);
            return it->second->second;
        }
        void put(T1 key, T2 value) {
            std::lock_guard<std::mutex> lock(mtx);
            auto it = cache.find(key);
            if (it != cache.end()){
                usage.splice(usage.begin(), usage, it->second);
                it->second->second = value;
                return;
            }
            if (cache.size() == capacity) {
                auto last = usage.back();
                cache.erase(last.first);
                usage.pop_back();
            }
            usage.emplace_front(key, value);
            cache[key] = usage.begin();
        }

};

int main(){

    fastio
    
    
    

    
    return 0;
}
