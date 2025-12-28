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
struct StackSample {
    double timestamp;
    std::vector<std::string> functions;
};
```

**Rules:**
- If a function appears in sample N but not in sample N-1 → it **started** at timestamp N
- If a function appears in sample N-1 but not in sample N → it **ended** at timestamp N
- For the first sample, all functions **started**
- For the last sample (if you want to close everything), remaining functions **ended** — or leave them open (your choice)
*/

struct StackSample {
    double timestamp;
    std::vector<std::string> functions;
};

std::vector<std::pair<double, std::string>> processStackSamples(const std::vector<StackSample>& samples) {

    std::vector<std::pair<double, std::string>> events;
    std::set<std::string> previousFunctions;

    for (size_t i = 0; i < samples.size(); ++i){
        const auto& sample = samples[i];
        std::set<std::string> currentFunctions(sample.functions.begin(), sample.functions.end());

        for (const auto& func : currentFunctions) {
            if (previousFunctions.find(func) == previousFunctions.end()) {
                events.emplace_back(sample.timestamp, "started " + func);
            }
        }

    
        for (const auto& func : previousFunctions) {
            if (currentFunctions.find(func) == currentFunctions.end()) {
                events.emplace_back(sample.timestamp, "ended " + func);
            }
        }

        previousFunctions = currentFunctions;
    }

    return events;
}


int main(){

    fastio
    std::vector<StackSample> samples = {
        {1.5, {"main", "fn1", "fn2"}},
        {4.5, {"main"}},
        {7.8, {}}
    };
    auto events = processStackSamples(samples);
    for (const auto& event : events) {
        std::cout << event.first << " " << event.second << std::endl;
    }

    cout << std::endl;
    cout << "Example 2" << endl;
    std::vector<StackSample> complexSamples = {
        {0.0, {"main"}},
        {1.0, {"main", "A"}},
        {2.0, {"main", "A", "B"}},
        {3.0, {"main", "C"}},
        {4.0, {"main"}},
        {5.0, {}}
    };
    auto complexEvents = processStackSamples(complexSamples);
    for (const auto& event : complexEvents) {
        std::cout << event.first << " " << event.second << std::endl;
    }

    
    
    

    
    return 0;
}
