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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

///__builtin_popcount(x)

ifstream cin("date.in");
ofstream cout("date.out");

const int N = 9;
const int dl[] = {0, 0, 1, 1};
const int dc[] = {0, 1, 0, 1};

int dala, a[1<<N][1<<N], n;

bool interior(int l_colt, int c_colt, int lat, int l_lipsa, int c_lipsa){

    return (l_colt <= l_lipsa && l_lipsa < l_colt + lat && c_colt <= c_lipsa && c_lipsa < c_colt + lat);

}
void pav(int l_colt, int c_colt, int lat, int l_lipsa, int c_lipsa){

    if (lat == 1){   
        return;
    }
    
    lat /= 2;
    int dala_loc = ++dala;
    for (int i = 0; i < 4; i++){

        int l_colt_c = l_colt + lat * dl[i];
        int c_colt_c = c_colt + lat * dc[i];

        if(!interior(l_colt_c, c_colt_c, lat, l_lipsa, c_lipsa)){
            int l_centru = l_colt + lat - (1 - dl[i]);
            int c_centru = c_colt + lat - (1 - dc[i]);
            a[l_centru][c_centru] = dala_loc;
        
            pav(l_colt_c, c_colt_c, lat, l_centru, c_centru);

        
        }
        else
            pav(l_colt_c, c_colt_c, lat, l_lipsa, c_lipsa);
        
    }
}

int main(){

    int l, c;
    cin >> n >> l >> c;
    l--;
    c--;
    pav(0, 0, 1 << n, l, c);
    
    for(int i = 0; i < (1 << n); i++){
        for (int j = 0; j < (1 << n); j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
