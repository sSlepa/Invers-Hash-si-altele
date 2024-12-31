/// Creat cu ajutoru lu Luci EZ
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
#include <random>
#pragma warning(disable:4996)

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define MOD 1000000009
#define MODC 984162944621615797
#define lsb(i) (i & -i)
#define pii pair<int,int>
#define tup tuple<int,int,int>
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

///__builtin_popcount(x)

ifstream cin("date.in");
ofstream cout("date.out");

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll inmultire(ll a, ll b, ll mod){
    ll ans = 0;
    for (; b; b >>= 1){
        if (b&1){
             ans += a;
            if (ans >= mod)   
                ans -= mod;
      }
      a <<= 1;

      if(a >= mod)  
        a -= mod;
    }
    return ans;
}

ll ezpow(ll a, ll b, ll mod){
    ll ans = 1;
    for (; b; b >>= 1){
      if(b&1)
        ans = (ll) inmultire(ans,a,mod);

    a = (ll) inmultire(a,a,mod);
    }

   return ans;
}


bool prim(ll x){// https://en.wikipedia.org/wiki/Fermat_primality_test
    if(x == 1)
        return 0;
    if (x <= 3)
        return 1;
   
    for (int t = 0; t < 10; ++t){
       ll a = 2 + rng() % (x-3);
       if (ezpow(a, x-1, x) != 1)
          return 0; // sigur neprim
    }
    return 1; // probabil prim
}


int main(){

    fastio
    unsigned ll a;
    
    cin >> a;
    if (prim(a))
        cout << "YES";
    else
        cout << "NO";
    
    


    return 0;
}
