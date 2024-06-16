#include <fstream>
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
#include <random>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define MOD 1000000007
#define MODC 984162946217979097
#define lsb(i) (i & -i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tup tuple<int,int,int>
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

///__builtin_popcount(x)

ifstream cin("date.in");
ofstream cout("date.out");

using namespace std;

int n;
int a[100005];
vector<int> vals;

int main(){
 
    fastio;

    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        vals.push_back(a[i]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for(int i = 1 ; i <= n ; ++i)
        a[i] = upper_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    

    
    return 0;
}
